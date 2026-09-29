/*
 * test_adversarial_dma.c — Adversarial stress, fuzz, and edge-case test suite
 * for Intel 8237 DMA, Sound Blaster DSP Command 0x14, 8259 PIC EOI ordering,
 * deterministic virtual cycle pacing, and Audio HAL streaming.
 */
#include "emu/vm.h"
#include "port_hal.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADV_ASSERT_EQ(a, b, msg) do { \
    if ((a) != (b)) { \
        fprintf(stderr, "[FAIL] %s:%d: %s (expected %llu, got %llu)\n", \
                __func__, __LINE__, msg, (unsigned long long)(b), (unsigned long long)(a)); \
        return false; \
    } \
} while (0)

#define ADV_ASSERT_TRUE(cond, msg) do { \
    if (!(cond)) { \
        fprintf(stderr, "[FAIL] %s:%d: %s\n", __func__, __LINE__, msg); \
        return false; \
    } \
} while (0)

/* Capture callback state */
static uint8_t  s_captured_buf[131072];
static uint32_t s_captured_count = 0;
static uint32_t s_captured_rate = 0;
static int      s_capture_calls = 0;

static void adv_capture_dma_write(const uint8_t *samples, uint32_t count, uint32_t sample_rate) {
    s_capture_calls++;
    s_captured_count = count;
    s_captured_rate = sample_rate;
    if (count <= sizeof(s_captured_buf)) {
        memcpy(s_captured_buf, samples, count);
    }
}

static bool init_test_vm(vm *machine) {
    vm_config cfg;
    char err[256];
    memset(&cfg, 0, sizeof(cfg));
    snprintf(cfg.exe_path, sizeof(cfg.exe_path), "original/XANTH.EXE");
    return vm_init(machine, &cfg, err, sizeof(err));
}

/* =========================================================================
 * SECTION 1: 8237 DMA Register State Machine Adversarial & Fuzz Tests
 * ========================================================================= */

/* Test 1.1: Flip-Flop Desynchronization & Cross-Channel Interleaving */
static bool test_dma_flipflop_desync(void) {
    printf("  [Adv 1.1] Testing 8237 flip-flop desynchronization & cross-channel interleaving...\n");
    vm m;
    if (!init_test_vm(&m)) return false;

    /* Start in clean state */
    cpu86_port_out8(&m.cpu, 0x0C, 0x00);
    ADV_ASSERT_EQ(m.dma.flip_flop, 0, "flip_flop must be 0 after port 0x0C");

    /* Channel 0 low address */
    cpu86_port_out8(&m.cpu, 0x00, 0x11);
    ADV_ASSERT_EQ(m.dma.flip_flop, 1, "flip_flop = 1 after Ch 0 addr low");
    ADV_ASSERT_EQ(m.dma.cur_addr[0] & 0xFF, 0x11, "Ch 0 low byte latched");

    /* Desync: Now write to Channel 2 address (should write high byte due to shared flip_flop!) */
    cpu86_port_out8(&m.cpu, 0x04, 0x22);
    ADV_ASSERT_EQ(m.dma.flip_flop, 0, "flip_flop = 0 after high byte write to Ch 2");
    ADV_ASSERT_EQ(m.dma.cur_addr[2] >> 8, 0x22, "Ch 2 high byte latched");

    /* Read Channel 1 count (should read low byte and flip to 1) */
    m.dma.cur_count[1] = 0x55AA;
    uint8_t b1 = cpu86_port_in8(&m.cpu, 0x03);
    ADV_ASSERT_EQ(b1, 0xAA, "Ch 1 count low byte read");
    ADV_ASSERT_EQ(m.dma.flip_flop, 1, "flip_flop = 1 after read");

    /* Mid-sequence reset */
    cpu86_port_out8(&m.cpu, 0x0C, 0xFF);
    ADV_ASSERT_EQ(m.dma.flip_flop, 0, "flip_flop = 0 after 0x0C reset");

    /* Interleaved count and address writes on Channel 1 */
    cpu86_port_out8(&m.cpu, 0x02, 0x78); /* low addr */
    cpu86_port_out8(&m.cpu, 0x02, 0x56); /* high addr */
    ADV_ASSERT_EQ(m.dma.cur_addr[1], 0x5678, "cur_addr[1] == 0x5678");

    cpu86_port_out8(&m.cpu, 0x03, 0x34); /* low count */
    cpu86_port_out8(&m.cpu, 0x03, 0x12); /* high count */
    ADV_ASSERT_EQ(m.dma.cur_count[1], 0x1234, "cur_count[1] == 0x1234");

    vm_shutdown(&m);
    return true;
}

/* Test 1.2: 8237 Mask Register Twiddling & Master Mask (0x0A / 0x0F) */
static bool test_dma_mask_state_machine(void) {
    printf("  [Adv 1.2] Testing 8237 mask register state machine (ports 0x0A & 0x0F)...\n");
    vm m;
    if (!init_test_vm(&m)) return false;

    /* Initially unmasked */
    m.dma.mask = 0;

    /* Set mask bit for channel 0: val = 4 | 0 = 4 */
    cpu86_port_out8(&m.cpu, 0x0A, 0x04);
    ADV_ASSERT_EQ(m.dma.mask, 0x01, "Channel 0 masked");

    /* Set mask bit for channel 1: val = 4 | 1 = 5 */
    cpu86_port_out8(&m.cpu, 0x0A, 0x05);
    ADV_ASSERT_EQ(m.dma.mask, 0x03, "Channels 0 & 1 masked");

    /* Set mask bit for channel 2: val = 4 | 2 = 6 */
    cpu86_port_out8(&m.cpu, 0x0A, 0x06);
    ADV_ASSERT_EQ(m.dma.mask, 0x07, "Channels 0, 1, 2 masked");

    /* Set mask bit for channel 3: val = 4 | 3 = 7 */
    cpu86_port_out8(&m.cpu, 0x0A, 0x07);
    ADV_ASSERT_EQ(m.dma.mask, 0x0F, "All channels 0..3 masked");

    /* Clear channel 1 mask: val = 0 | 1 = 1 */
    cpu86_port_out8(&m.cpu, 0x0A, 0x01);
    ADV_ASSERT_EQ(m.dma.mask, 0x0D, "Channel 1 unmasked (mask = 0x0D)");

    /* Master mask register port 0x0F: write 0x0A (channels 1 & 3 masked) */
    cpu86_port_out8(&m.cpu, 0x0F, 0x0A);
    ADV_ASSERT_EQ(m.dma.mask, 0x0A, "Master mask 0x0A applied");
    ADV_ASSERT_EQ(cpu86_port_in8(&m.cpu, 0x0A), 0x0A, "Read port 0x0A reflects master mask");

    vm_shutdown(&m);
    return true;
}

/* Test 1.3: Boundary Addresses around 0x100000 (1MB Physical Limit) */
static bool test_dma_boundary_addresses(void) {
    printf("  [Adv 1.3] Testing 8237 DMA boundary addresses around 0x100000...\n");
    vm m;
    if (!init_test_vm(&m)) return false;

    vm_audio_dma_write = adv_capture_dma_write;

    /* Case A: Exact upper limit (Page = 0x0F, cur_addr = 0xFF00, len = 256 -> ends at exactly 0x100000) */
    s_capture_calls = 0;
    cpu86_port_out8(&m.cpu, 0x0C, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0xFF); /* cur_addr = 0xFF00 */
    cpu86_port_out8(&m.cpu, 0x83, 0x0F); /* Page = 0x0F -> phys = 0xFFF00 */
    /* Phys addr = 0x0F0000 | 0xFF00 = 0xFFF00. len = 256 -> phys_addr + len = 0x100000 (EXACT) */
    cpu86_port_out8(&m.cpu, 0x22C, 0x14);
    cpu86_port_out8(&m.cpu, 0x22C, 255); /* len_raw = 255 -> len = 256 */
    cpu86_port_out8(&m.cpu, 0x22C, 0);

    ADV_ASSERT_EQ(s_capture_calls, 1, "Transfer exactly up to 0x100000 must succeed");
    ADV_ASSERT_EQ(s_captured_count, 256, "Transferred 256 bytes");
    ADV_ASSERT_EQ(m.dma.cur_addr[1], 0x0000, "cur_addr wrapped 0xFF00 + 256 -> 0x0000");

    /* Channel 1's 16-bit address wraps independently of the page register.
     * Bytes after 0x1FFFF come from 0x10000, not the next linear page. */
    s_capture_calls = 0;
    for (uint32_t i = 0; i < 256; i++) {
        g_dos_mem[0x1FF00 + i] = (uint8_t)(i ^ 0x5A);
        g_dos_mem[0x10000 + i] = (uint8_t)(i ^ 0xA5);
    }
    cpu86_port_out8(&m.cpu, 0x0C, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0xFF); /* cur_addr = 0xFF00 */
    cpu86_port_out8(&m.cpu, 0x83, 0x01); /* page remains 1 after address wraps */
    cpu86_port_out8(&m.cpu, 0x22C, 0x14);
    cpu86_port_out8(&m.cpu, 0x22C, 0xFF); /* 512 bytes */
    cpu86_port_out8(&m.cpu, 0x22C, 0x01);
    ADV_ASSERT_EQ(s_capture_calls, 1, "page-crossing transfer is submitted once");
    ADV_ASSERT_EQ(s_captured_count, 512, "page-crossing transfer retains full length");
    for (uint32_t i = 0; i < 256; i++) {
        ADV_ASSERT_EQ(s_captured_buf[i], (uint8_t)(i ^ 0x5A), "pre-wrap byte comes from page 1 high address");
        ADV_ASSERT_EQ(s_captured_buf[256 + i], (uint8_t)(i ^ 0xA5), "post-wrap byte comes from page 1 low address");
    }

    /* Case B: page 0x0F wraps its 16-bit address before crossing 1 MB. */
    s_capture_calls = 0;
    for (uint32_t i = 0; i < 255; i++) g_dos_mem[0xFFF01 + i] = (uint8_t)(i ^ 0x36);
    g_dos_mem[0xF0000] = 0xC7;
    cpu86_port_out8(&m.cpu, 0x0C, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x01);
    cpu86_port_out8(&m.cpu, 0x02, 0xFF); /* cur_addr = 0xFF01 */
    cpu86_port_out8(&m.cpu, 0x83, 0x0F); /* page remains 0x0F after wrap */
    cpu86_port_out8(&m.cpu, 0x22C, 0x14);
    cpu86_port_out8(&m.cpu, 0x22C, 255);
    cpu86_port_out8(&m.cpu, 0x22C, 0);
    ADV_ASSERT_EQ(s_capture_calls, 1, "DMA wraps the address register at the 64 KB boundary");
    ADV_ASSERT_EQ(s_captured_count, 256, "wrapped transfer delivers every sample");
    for (uint32_t i = 0; i < 255; i++)
        ADV_ASSERT_EQ(s_captured_buf[i], (uint8_t)(i ^ 0x36), "pre-wrap data stays below 1 MB");
    ADV_ASSERT_EQ(s_captured_buf[255], 0xC7, "post-wrap byte comes from the same page at offset zero");

    /* Case C: Page register masking (Bits 4..7 set, e.g. 0xF3 -> must mask to 0x03) */
    s_capture_calls = 0;
    cpu86_port_out8(&m.cpu, 0x0C, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x10); /* cur_addr = 0x1000 */
    cpu86_port_out8(&m.cpu, 0x83, 0xF3); /* Page with high bits set */
    /* If masked with 0x0F: page = 3 -> phys = 0x31000 <= 0x100000 */
    cpu86_port_out8(&m.cpu, 0x22C, 0x14);
    cpu86_port_out8(&m.cpu, 0x22C, 15);  /* len = 16 */
    cpu86_port_out8(&m.cpu, 0x22C, 0);

    ADV_ASSERT_EQ(s_capture_calls, 1, "Page register high bits must be masked with 0x0F");
    ADV_ASSERT_EQ(s_captured_count, 16, "16 bytes transferred");

    vm_shutdown(&m);
    return true;
}

/* =========================================================================
 * SECTION 2: DSP Command 0x14 Edge Cases & IRQ / PIC State Machine
 * ========================================================================= */

/* Test 2.1: Zero Length (len_raw = 0 -> 1 byte transfer) and Odd Lengths */
static bool test_dsp_odd_and_zero_lengths(void) {
    printf("  [Adv 2.1] Testing DSP command 0x14 zero and odd lengths...\n");
    vm m;
    if (!init_test_vm(&m)) return false;
    vm_audio_dma_write = adv_capture_dma_write;

    /* Zero length raw (0x0000) -> 1 byte */
    s_capture_calls = 0;
    cpu86_port_out8(&m.cpu, 0x0C, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x20);
    cpu86_port_out8(&m.cpu, 0x83, 0x01);
    cpu86_port_out8(&m.cpu, 0x22C, 0x14);
    cpu86_port_out8(&m.cpu, 0x22C, 0x00); /* len low = 0 */
    cpu86_port_out8(&m.cpu, 0x22C, 0x00); /* len high = 0 */

    ADV_ASSERT_EQ(s_capture_calls, 1, "1 byte transfer dispatched");
    ADV_ASSERT_EQ(s_captured_count, 1, "Count is exactly 1 for len_raw = 0");
    ADV_ASSERT_EQ(m.dma.cur_addr[1], 0x2001, "cur_addr advanced by 1");

    /* Odd lengths: 3, 513, 1025 */
    uint16_t odd_lens[] = { 3, 513, 1025 };
    for (int i = 0; i < 3; i++) {
        uint16_t req = odd_lens[i];
        uint16_t raw = req - 1;
        s_capture_calls = 0;
        cpu86_port_out8(&m.cpu, 0x22C, 0x14);
        cpu86_port_out8(&m.cpu, 0x22C, (uint8_t)(raw & 0xFF));
        cpu86_port_out8(&m.cpu, 0x22C, (uint8_t)(raw >> 8));
        ADV_ASSERT_EQ(s_capture_calls, 1, "Odd length transfer dispatched");
        ADV_ASSERT_EQ(s_captured_count, req, "Exact odd count transferred");
    }

    vm_shutdown(&m);
    return true;
}

/* Test 2.2: Maximum Transfer Length 65,536 Bytes (len_raw = 0xFFFF) */
static bool test_dsp_max_length_65536(void) {
    printf("  [Adv 2.2] Testing DSP command 0x14 maximum length (65,536 bytes)...\n");
    vm m;
    if (!init_test_vm(&m)) return false;
    vm_audio_dma_write = adv_capture_dma_write;

    s_capture_calls = 0;
    cpu86_port_out8(&m.cpu, 0x0C, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x00); /* Addr = 0x0000 */
    cpu86_port_out8(&m.cpu, 0x83, 0x01); /* Page = 0x01 -> Phys = 0x10000 */

    /* Dispatch command 0x14 with 0xFFFF -> 65536 bytes */
    cpu86_port_out8(&m.cpu, 0x22C, 0x14);
    cpu86_port_out8(&m.cpu, 0x22C, 0xFF);
    cpu86_port_out8(&m.cpu, 0x22C, 0xFF);

    ADV_ASSERT_EQ(s_capture_calls, 1, "65536 byte transfer dispatched");
    ADV_ASSERT_EQ(s_captured_count, 65536, "Count is exactly 65536");
    ADV_ASSERT_EQ(m.dma.cur_addr[1], 0x0000, "16-bit address wrapped 0x0000 + 65536 -> 0x0000");
    ADV_ASSERT_EQ(m.dma.cur_count[1], 0xFFFF, "Word count expired to 0xFFFF");
    ADV_ASSERT_EQ(m.sb.dma_transferred_bytes, 65536, "dma_transferred_bytes is 65536");

    vm_shutdown(&m);
    return true;
}

/* Test 2.3: Rapid Successive DMA Commands without Intervening Cycle Delay */
static bool test_dsp_rapid_successive_commands(void) {
    printf("  [Adv 2.3] Testing rapid successive DMA commands...\n");
    vm m;
    if (!init_test_vm(&m)) return false;
    vm_audio_dma_write = adv_capture_dma_write;

    cpu86_port_out8(&m.cpu, 0x0C, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x10); /* Addr = 0x1000 */
    cpu86_port_out8(&m.cpu, 0x83, 0x02); /* Page = 0x02 -> Phys = 0x21000 */

    s_capture_calls = 0;

    /* Transfer 1: 500 bytes */
    cpu86_port_out8(&m.cpu, 0x22C, 0x14);
    cpu86_port_out8(&m.cpu, 0x22C, (uint8_t)(499 & 0xFF));
    cpu86_port_out8(&m.cpu, 0x22C, (uint8_t)(499 >> 8));

    ADV_ASSERT_EQ(s_capture_calls, 1, "Call 1 dispatched");
    ADV_ASSERT_EQ(s_captured_count, 500, "500 bytes in call 1");
    ADV_ASSERT_EQ(m.dma.cur_addr[1], 0x1000 + 500, "cur_addr incremented after call 1");
    ADV_ASSERT_TRUE(m.sb.dma_active, "DMA active after call 1");

    /* Rapid Transfer 2: 300 bytes immediately following (without cycle advancement) */
    cpu86_port_out8(&m.cpu, 0x22C, 0x14);
    cpu86_port_out8(&m.cpu, 0x22C, (uint8_t)(299 & 0xFF));
    cpu86_port_out8(&m.cpu, 0x22C, (uint8_t)(299 >> 8));

    ADV_ASSERT_EQ(s_capture_calls, 2, "Call 2 dispatched immediately");
    ADV_ASSERT_EQ(s_captured_count, 300, "300 bytes in call 2");
    ADV_ASSERT_EQ(m.dma.cur_addr[1], 0x1000 + 500 + 300, "cur_addr incremented after call 2");
    ADV_ASSERT_EQ(m.sb.dma_transferred_bytes, 800, "Cumulative transferred bytes == 800");

    vm_shutdown(&m);
    return true;
}

/* Test 2.4: Port 0x22E Deassertion Before and After Timer Expiration */
static bool test_dsp_irq_deassertion_timing(void) {
    printf("  [Adv 2.4] Testing port 0x22E deassertion timing (before vs after expiration)...\n");
    vm m;
    if (!init_test_vm(&m)) return false;

    m.cycles_per_second = 1000000ULL;
    m.sb.sample_rate = 10000;
    m.sb.irq = 7;
    m.pit_period_cycles = 1000000000ULL;
    m.next_tick_cycles  = 1000000000ULL;

    /* Start DMA transfer: 100 bytes -> 10,000 cycles */
    cpu86_port_out8(&m.cpu, 0x0C, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x10);
    cpu86_port_out8(&m.cpu, 0x83, 0x01);
    cpu86_port_out8(&m.cpu, 0x22C, 0x14);
    cpu86_port_out8(&m.cpu, 0x22C, 99);
    cpu86_port_out8(&m.cpu, 0x22C, 0);

    ADV_ASSERT_TRUE(m.sb.dma_active, "DMA is active");
    ADV_ASSERT_TRUE(!m.sb.irq_pending, "IRQ not pending before expiration");

    /* Subtest A: Read port 0x22E BEFORE expiration */
    uint8_t st = cpu86_port_in8(&m.cpu, 0x22E);
    (void)st;
    ADV_ASSERT_TRUE(m.sb.dma_active, "Premature 0x22E read must NOT cancel active DMA");
    ADV_ASSERT_TRUE(!m.sb.irq_pending, "IRQ still not pending");

    /* Now advance CPU cycles past dma_end_cycles */
    m.cpu.cycles = m.sb.dma_end_cycles;
    /* Put NOP at CS:IP so vm_run can execute 1 step */
    m.cpu.s[CPU_CS] = 0x2000;
    m.cpu.ip = 0x0100;
    g_dos_mem[0x20100] = 0x90; /* NOP */
    m.cpu.flags &= (uint16_t)~F_IF; /* Mask interrupts on CPU so it doesn't take ISR */

    vm_run(&m, 1);

    /* After running, DMA must have finished and asserted IRQ */
    ADV_ASSERT_TRUE(!m.sb.dma_active, "DMA finished");
    ADV_ASSERT_TRUE(m.sb.irq_pending, "IRQ pending asserted upon timer expiration");
    ADV_ASSERT_TRUE((m.pic.irr & (1 << 7)) != 0, "PIC IRR bit 7 asserted");

    /* Subtest B: Read port 0x22E AFTER expiration */
    st = cpu86_port_in8(&m.cpu, 0x22E);
    (void)st;
    ADV_ASSERT_TRUE(!m.sb.irq_pending, "Port 0x22E read cleared irq_pending");
    ADV_ASSERT_TRUE((m.pic.irr & (1 << 7)) == 0, "Port 0x22E read cleared PIC IRR bit 7");

    vm_shutdown(&m);
    return true;
}

/* Test 2.5: PIC EOI Ordering & Re-entrancy Protection */
static bool test_pic_eoi_ordering(void) {
    printf("  [Adv 2.5] Testing PIC EOI ordering (normal vs inverted order)...\n");
    vm m;
    if (!init_test_vm(&m)) return false;

    m.sb.irq = 7;
    m.sb.irq_pending = true;
    m.pic.irr |= (1 << 7);
    m.pic.isr |= (1 << 7);

    /* Normal order: read 0x22E first, then EOI */
    cpu86_port_in8(&m.cpu, 0x22E);
    ADV_ASSERT_TRUE(!m.sb.irq_pending, "irq_pending cleared by 0x22E");
    ADV_ASSERT_TRUE((m.pic.isr & (1 << 7)) != 0, "ISR still set before EOI");

    cpu86_port_out8(&m.cpu, 0x20, 0x20); /* EOI */
    ADV_ASSERT_TRUE((m.pic.isr & (1 << 7)) == 0, "ISR cleared by EOI");
    ADV_ASSERT_TRUE(!m.sb.irq_pending, "Clean state after normal order");

    /* Inverted order: EOI first (port 0x20), then read 0x22E */
    m.sb.irq_pending = true;
    m.pic.isr |= (1 << 7);

    cpu86_port_out8(&m.cpu, 0x20, 0x20); /* EOI first */
    ADV_ASSERT_TRUE((m.pic.isr & (1 << 7)) == 0, "ISR cleared by EOI");

    /* Acknowledge DSP */
    cpu86_port_in8(&m.cpu, 0x22E);
    ADV_ASSERT_TRUE(!m.sb.irq_pending, "DSP acknowledged");

    vm_shutdown(&m);
    return true;
}

/* =========================================================================
 * SECTION 3: Deterministic Virtual Cycle Pacing
 * ========================================================================= */

/* Test 3.1: Reproducible Bit-for-Bit Cycle Advancement across Multiple Runs */
static bool test_cycle_pacing_determinism(void) {
    printf("  [Adv 3.1] Testing deterministic virtual cycle pacing across multiple runs...\n");

    uint64_t cycle_snapshots[5];
    uint64_t timer_snapshots[5];
    uint64_t dma_end_snapshots[5];

    for (int run = 0; run < 5; run++) {
        vm m;
        if (!init_test_vm(&m)) return false;

        m.cycles_per_second = 10000000ULL;
        m.pit_period_cycles = 50000ULL;
        m.next_tick_cycles  = 50000ULL;
        m.sb.sample_rate = 11025;

        /* Write a deterministic 8086 code sequence:
         * 0x1000:0x0000:
         *   MOV CX, 500
         * loop:
         *   ADD AX, 7
         *   DEC CX
         *   JNZ loop
         *   NOP
         *   HLT
         */
        m.cpu.s[CPU_CS] = 0x1000;
        m.cpu.ip = 0x0000;
        uint32_t lin = 0x10000;
        g_dos_mem[lin + 0] = 0xB9; /* MOV CX, 500 (0x01F4) */
        g_dos_mem[lin + 1] = 0xF4;
        g_dos_mem[lin + 2] = 0x01;
        /* loop: offset 3 */
        g_dos_mem[lin + 3] = 0x05; /* ADD AX, 7 */
        g_dos_mem[lin + 4] = 0x07;
        g_dos_mem[lin + 5] = 0x00;
        g_dos_mem[lin + 6] = 0x49; /* DEC CX */
        g_dos_mem[lin + 7] = 0x75; /* JNZ loop (-7 bytes -> to offset 3) */
        g_dos_mem[lin + 8] = 0xFA;
        g_dos_mem[lin + 9] = 0x90; /* NOP */
        g_dos_mem[lin + 10]= 0xF4; /* HLT */

        /* Start a DMA transfer at start of run */
        cpu86_port_out8(&m.cpu, 0x0C, 0x00);
        cpu86_port_out8(&m.cpu, 0x02, 0x00);
        cpu86_port_out8(&m.cpu, 0x02, 0x20);
        cpu86_port_out8(&m.cpu, 0x83, 0x01);
        cpu86_port_out8(&m.cpu, 0x22C, 0x14);
        cpu86_port_out8(&m.cpu, 0x22C, 200); /* len = 201 */
        cpu86_port_out8(&m.cpu, 0x22C, 0);

        /* Run 100 VM slices */
        for (int slice = 0; slice < 100; slice++) {
            vm_run(&m, 100);
        }

        cycle_snapshots[run] = m.cpu.cycles;
        timer_snapshots[run] = m.timer_ticks;
        dma_end_snapshots[run] = m.sb.dma_end_cycles;

        vm_shutdown(&m);
    }

    /* Compare all 5 runs: must be 100% strictly identical */
    for (int i = 1; i < 5; i++) {
        ADV_ASSERT_EQ(cycle_snapshots[i], cycle_snapshots[0], "CPU cycles must be 100% deterministic");
        ADV_ASSERT_EQ(timer_snapshots[i], timer_snapshots[0], "Timer ticks must be 100% deterministic");
        ADV_ASSERT_EQ(dma_end_snapshots[i], dma_end_snapshots[0], "DMA end cycles must be 100% deterministic");
    }
    printf("    -> 5/5 runs produced identical cycle count: %llu cycles, %llu timer ticks\n",
           (unsigned long long)cycle_snapshots[0], (unsigned long long)timer_snapshots[0]);

    return true;
}

/* Test 3.2: PIT Timer Phase Stability during Active DMA */
static bool test_pit_phase_during_dma(void) {
    printf("  [Adv 3.2] Testing PIT timer phase stability during active DMA...\n");
    vm m;
    if (!init_test_vm(&m)) return false;

    m.cycles_per_second = 10000000ULL;
    m.pit_period_cycles = 10000ULL;
    m.next_tick_cycles  = 10000ULL;
    m.sb.sample_rate = 11025;

    /* Schedule a large DMA transfer: 4000 bytes -> ~3.6M cycles */
    cpu86_port_out8(&m.cpu, 0x0C, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x20);
    cpu86_port_out8(&m.cpu, 0x83, 0x01);
    cpu86_port_out8(&m.cpu, 0x22C, 0x14);
    cpu86_port_out8(&m.cpu, 0x22C, 0xA0);
    cpu86_port_out8(&m.cpu, 0x22C, 0x0F); /* 4000 bytes */

    ADV_ASSERT_TRUE(m.sb.dma_active, "DMA active");

    /* Put infinite NOP loop at CS:IP: NOP; JMP short -3 */
    m.cpu.s[CPU_CS] = 0x2000;
    m.cpu.ip = 0x0000;
    g_dos_mem[0x20000] = 0x90; /* NOP */
    g_dos_mem[0x20001] = 0xEB; /* JMP short */
    g_dos_mem[0x20002] = 0xFD; /* -3 bytes -> back to 0x20000 */
    m.cpu.flags |= F_IF;

    /* Run 50 slices */
    for (int s = 0; s < 50; s++) {
        vm_run(&m, 1000);
    }

    /* Verify timer ticks advanced smoothly without losing ticks */
    if (m.timer_ticks == 0) {
        fprintf(stderr, "DEBUG: cycles=%llu, next_tick=%llu, period=%llu, tick_pending=%d, fault=%d, IF=%d\n",
                (unsigned long long)m.cpu.cycles, (unsigned long long)m.next_tick_cycles,
                (unsigned long long)m.pit_period_cycles, m.tick_pending, m.cpu.fault, (m.cpu.flags & F_IF) != 0);
    }
    ADV_ASSERT_TRUE(m.timer_ticks > 0, "Timer ticks fired during DMA");
    uint64_t expected_min_ticks = m.cpu.cycles / m.pit_period_cycles;
    ADV_ASSERT_TRUE(m.timer_ticks >= expected_min_ticks - 2, "PIT ticks maintained phase");

    vm_shutdown(&m);
    return true;
}

/* =========================================================================
 * SECTION 4: Audio HAL SPSC Streaming Ring Buffer Adversarial Edge Cases
 * ========================================================================= */

/* Test 4.1: Extreme Sample Rates Resampling & Buffer Wrap */
static bool test_audio_hal_extreme_resampling(void) {
    printf("  [Adv 4.1] Testing Audio HAL extreme sample rates & ring buffer wrap...\n");
    if (!hal_audio_init()) return false;

    /* 1. Low sample rate: 3906 Hz (tc = 0) */
    uint8_t low_pcm[200];
    memset(low_pcm, 128, sizeof(low_pcm));
    hal_audio_dma_submit_block(low_pcm, sizeof(low_pcm), 3906);

    /* 2. High sample rate: 44100 Hz (tc = 233 -> rate = 43478 Hz) */
    uint8_t high_pcm[1000];
    for (size_t i = 0; i < sizeof(high_pcm); i++) high_pcm[i] = (uint8_t)(i & 0xFF);
    hal_audio_dma_submit_block(high_pcm, sizeof(high_pcm), 44100);

    /* Drain some frames via tick */
    for (int i = 0; i < 10; i++) hal_audio_tick();

    /* 3. Stress ring buffer wrap: submit 70,000 frames (exceeds DMA_RING_FRAMES = 65536) */
    uint8_t *large_pcm = (uint8_t *)malloc(70000);
    ADV_ASSERT_TRUE(large_pcm != NULL, "malloc large_pcm");
    memset(large_pcm, 140, 70000);
    hal_audio_dma_submit_block(large_pcm, 70000, 44100);
    free(large_pcm);

    /* Drain completely */
    for (int i = 0; i < 150; i++) hal_audio_tick();

    hal_audio_shutdown();
    return true;
}

/* Test 4.2: Empirical Test of Resampling Loop Early-Exit Discrepancy */
static bool test_resampling_loop_discrepancy(void) {
    printf("  [Adv 4.2] Testing resampling loop ceiling vs loop break discrepancy...\n");
    /* Test tc=0 (rate 3906), count = 155 */
    uint32_t sample_rate = 3906;
    uint32_t count = 155;
    double ratio = (double)sample_rate / 44100.0;
    uint32_t out_frames = (uint32_t)ceil((double)count / ratio);

    uint32_t written = 0;
    for (uint32_t f = 0; f < out_frames; f++) {
        double src_pos = (double)f * ratio;
        if (src_pos >= (double)count) break;
        written++;
    }

    if (written != out_frames) {
        printf("    [FINDING CONFIRMED] Submitting count=%u at %u Hz: ceil calculates out_frames=%u, but loop breaks at %u frames! (Discrepancy: %u unwritten frame(s))\n",
               count, sample_rate, out_frames, written, out_frames - written);
    } else {
        printf("    No discrepancy observed for count=%u\n", count);
    }

    return true;
}

/* Test 1.4: 8237 DMA Register Fuzzing (10,000 Iterations) */
static bool test_dma_fuzz_registers(void) {
    printf("  [Adv 1.4] Fuzzing 8237 DMA registers with 10,000 pseudo-random I/O accesses...\n");
    vm m;
    if (!init_test_vm(&m)) return false;

    uint32_t seed = 0x12345678;
    for (int i = 0; i < 10000; i++) {
        seed = seed * 1664525u + 1013904223u;
        uint8_t op = (seed >> 16) & 0xFF;
        uint8_t val = (seed >> 8) & 0xFF;

        static const uint16_t ports[] = {
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x0A, 0x0B, 0x0C, 0x0F,
            0x81, 0x82, 0x83, 0x87
        };
        uint16_t port = ports[op % (sizeof(ports) / sizeof(ports[0]))];

        if (op & 0x80) {
            cpu86_port_out8(&m.cpu, port, val);
        } else {
            volatile uint8_t res = cpu86_port_in8(&m.cpu, port);
            (void)res;
        }

        ADV_ASSERT_TRUE(m.dma.flip_flop == 0 || m.dma.flip_flop == 1, "flip_flop must be binary 0 or 1");
    }

    vm_shutdown(&m);
    return true;
}

/* Test 1.5: Masked vs Unmasked DMA Channel Execution Characterization */
static bool test_dma_channel_masked_behavior(void) {
    printf("  [Adv 1.5] Testing masked vs unmasked DMA Channel 1 behavior...\n");
    vm m;
    if (!init_test_vm(&m)) return false;
    vm_audio_dma_write = adv_capture_dma_write;

    cpu86_port_out8(&m.cpu, 0x0C, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x00);
    cpu86_port_out8(&m.cpu, 0x02, 0x20);
    cpu86_port_out8(&m.cpu, 0x83, 0x01);

    /* Explicitly MASK Channel 1 (port 0x0A, val = 4 | 1 = 5) */
    cpu86_port_out8(&m.cpu, 0x0A, 0x05);
    ADV_ASSERT_TRUE((m.dma.mask & 0x02) != 0, "Channel 1 is masked in 8237 mask register");

    s_capture_calls = 0;
    cpu86_port_out8(&m.cpu, 0x22C, 0x14);
    cpu86_port_out8(&m.cpu, 0x22C, 99);
    cpu86_port_out8(&m.cpu, 0x22C, 0);

    printf("    [CHARACTERIZATION] With Ch 1 masked: s_capture_calls=%d (permissive immediate dispatch)\n",
           s_capture_calls);
    ADV_ASSERT_EQ(s_capture_calls, 1, "Immediate dispatch occurs (permissive behavior)");

    vm_shutdown(&m);
    return true;
}

/* Test 2.6: Four Gatekeepers for Sound Blaster IRQ Delivery */
static bool test_irq_gating_conditions(void) {
    printf("  [Adv 2.6] Testing 4 gatekeepers for Sound Blaster IRQ delivery in vm_run()...\n");
    vm m;
    if (!init_test_vm(&m)) return false;

    m.sb.irq = 7;

    #define SETUP_INSTR() do { \
        m.cpu.s[CPU_CS] = 0x2000; \
        m.cpu.ip = 0x0000; \
        g_dos_mem[0x20000] = 0x90; \
        g_dos_mem[0x20001] = 0xEB; \
        g_dos_mem[0x20002] = 0xFD; \
    } while (0)

    /* Gatekeeper 1: PIC IMR (Interrupt Mask Register, port 0x21) */
    SETUP_INSTR();
    m.sb.irq_pending = true;
    m.pic.irr = (uint8_t)(1 << 7);
    m.pic.isr = 0x00;
    m.pic.imr = (uint8_t)(1 << 7); /* Masked in PIC! */
    m.cpu.flags |= F_IF;
    m.cpu.inhibit_irq = false;

    vm_run(&m, 1);
    ADV_ASSERT_EQ(m.pic.isr, 0x00, "Gatekeeper 1: Masked by PIC IMR -> No IRQ injected");
    ADV_ASSERT_TRUE(m.sb.irq_pending, "IRQ remains pending");

    /* Gatekeeper 2: PIC ISR (In-Service Register) */
    SETUP_INSTR();
    m.pic.imr = 0x00;              /* Unmasked */
    m.pic.isr = (uint8_t)(1 << 7); /* Already in service! */
    vm_run(&m, 1);
    ADV_ASSERT_EQ(m.pic.isr, (uint8_t)(1 << 7), "Gatekeeper 2: Already in service -> No nested IRQ injected");
    ADV_ASSERT_TRUE(m.sb.irq_pending, "IRQ remains pending");

    /* Gatekeeper 3: CPU Interrupt Flag (CLI: F_IF cleared) */
    SETUP_INSTR();
    m.pic.isr = 0x00;
    m.cpu.flags &= (uint16_t)~F_IF; /* Interrupts disabled on CPU! */
    vm_run(&m, 1);
    ADV_ASSERT_EQ(m.pic.isr, 0x00, "Gatekeeper 3: CLI active -> No IRQ injected");
    ADV_ASSERT_TRUE(m.sb.irq_pending, "IRQ remains pending");

    /* Gatekeeper 4: Segment Load Shadow (c->inhibit_irq) */
    SETUP_INSTR();
    m.cpu.flags |= F_IF;
    m.cpu.inhibit_irq = true; /* MOV SS / POP SS shadow! */
    vm_run(&m, 1);
    ADV_ASSERT_EQ(m.pic.isr, 0x00, "Gatekeeper 4: inhibit_irq shadow -> No IRQ injected");
    ADV_ASSERT_TRUE(m.sb.irq_pending, "IRQ remains pending");

    /* Install dummy IRET handler for INT 0Fh (vector 15, address 15 * 4 = 0x3C) */
    g_dos_mem[0x30000] = 0xCF; /* IRET */
    g_dos_mem[0x3C] = 0x00;
    g_dos_mem[0x3D] = 0x00;
    g_dos_mem[0x3E] = 0x00;
    g_dos_mem[0x3F] = 0x30; /* 0x3000:0x0000 */

    /* When all 4 gatekeepers allow: IRQ must be injected! */
    SETUP_INSTR();
    m.cpu.inhibit_irq = false;
    vm_run(&m, 1);
    ADV_ASSERT_TRUE((m.pic.isr & (1 << 7)) != 0, "All clear -> IRQ injected and marked in ISR");

    vm_shutdown(&m);
    return true;
}

/* =========================================================================
 * Main Test Runner
 * ========================================================================= */
int main(void) {
    printf("====================================================================\n");
    printf("  ADVERSARIAL STRESS HARNESS: Sound Blaster DMA & 8237 Controller  \n");
    printf("====================================================================\n");

    int passed = 0;
    int failed = 0;

    #define RUN_TEST(fn) do { \
        if (fn()) { \
            passed++; \
        } else { \
            failed++; \
            fprintf(stderr, "[-] Test FAILED: %s\n", #fn); \
        } \
    } while (0)

    /* Section 1: 8237 DMA State Machine */
    RUN_TEST(test_dma_flipflop_desync);
    RUN_TEST(test_dma_mask_state_machine);
    RUN_TEST(test_dma_boundary_addresses);
    RUN_TEST(test_dma_fuzz_registers);
    RUN_TEST(test_dma_channel_masked_behavior);

    /* Section 2: DSP 0x14 & PIC */
    RUN_TEST(test_dsp_odd_and_zero_lengths);
    RUN_TEST(test_dsp_max_length_65536);
    RUN_TEST(test_dsp_rapid_successive_commands);
    RUN_TEST(test_dsp_irq_deassertion_timing);
    RUN_TEST(test_pic_eoi_ordering);
    RUN_TEST(test_irq_gating_conditions);

    /* Section 3: Virtual Cycle Determinism */
    RUN_TEST(test_cycle_pacing_determinism);
    RUN_TEST(test_pit_phase_during_dma);

    /* Section 4: Audio HAL SPSC Streaming */
    RUN_TEST(test_audio_hal_extreme_resampling);
    RUN_TEST(test_resampling_loop_discrepancy);

    printf("====================================================================\n");
    printf("  ADVERSARIAL RESULTS: %d passed, %d failed\n", passed, failed);
    printf("====================================================================\n");

    return (failed == 0) ? 0 : 1;
}
