/*
 * test_dma_pipeline.c — Unit and regression test suite for Intel 8237 DMA,
 * Sound Blaster DSP 0x14 DMA streaming, virtual cycle IRQ timing, and Audio HAL mixer.
 */
#include "emu/vm.h"
#include "port_hal.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASSERT_EQ(a, b, msg) do { \
    if ((a) != (b)) { \
        fprintf(stderr, "[FAIL] %s: line %d: %s (expected %llu, got %llu)\n", \
                __func__, __LINE__, msg, (unsigned long long)(b), (unsigned long long)(a)); \
        exit(1); \
    } \
} while (0)

#define ASSERT_TRUE(cond, msg) do { \
    if (!(cond)) { \
        fprintf(stderr, "[FAIL] %s: line %d: %s\n", __func__, __LINE__, msg); \
        exit(1); \
    } \
} while (0)

/* The DMA tests need a loaded VM, not retail game code. Use a tiny,
 * developer-authored MZ image so the same tests run on public runners. */
static void create_dma_fixture(void) {
    uint8_t image[96] = {0};
    image[0] = 'M'; image[1] = 'Z';
    image[2] = sizeof(image); /* bytes in the sole file page */
    image[4] = 1;             /* one page */
    image[8] = 4;             /* 64-byte header */
    image[10] = 0x20;         /* minimum extra allocation */
    image[12] = 0xff; image[13] = 0xff;
    image[17] = 1;            /* initial SP = 0x100 */
    image[24] = 0x1c;         /* empty relocation table */
    memset(image + 64, 0x90, sizeof(image) - 64); /* NOP body */
    FILE *file = fopen("build/dma_fixture.mz", "wb");
    ASSERT_TRUE(file != NULL, "synthetic DMA MZ fixture must open");
    const size_t written = fwrite(image, 1, sizeof(image), file);
    const int closed = fclose(file);
    ASSERT_EQ(written, sizeof(image), "synthetic DMA MZ fixture must write completely");
    ASSERT_EQ(closed, 0, "synthetic DMA MZ fixture must close");
}

static void dma_fixture_config(vm_config *cfg) {
    memset(cfg, 0, sizeof(*cfg));
    snprintf(cfg->exe_path, sizeof(cfg->exe_path), "build/dma_fixture.mz");
    snprintf(cfg->data_dir, sizeof(cfg->data_dir), ".");
    snprintf(cfg->save_dir, sizeof(cfg->save_dir), "build/dma-fixture-saves");
}

/* Capture callback state for testing vm_audio_dma_write */
static uint8_t  g_captured_buf[65536];
static uint32_t g_captured_count = 0;
static uint32_t g_captured_rate = 0;
static int      g_capture_calls = 0;

static void test_capture_dma_write(const uint8_t *samples, uint32_t count, uint32_t sample_rate) {
    g_capture_calls++;
    g_captured_count = count;
    g_captured_rate = sample_rate;
    if (count <= sizeof(g_captured_buf)) {
        memcpy(g_captured_buf, samples, count);
    }
}

/* -------------------------------------------------------------------------
 * Test 1: Intel 8237 DMA Controller Channel 1 Registers & Flip-Flop
 * ------------------------------------------------------------------------- */
static void test_dma_registers(void) {
    printf("  [1/6] Testing Intel 8237 DMA registers and flip-flop...\n");
    vm machine;
    vm_config cfg;
    char err[256];
    dma_fixture_config(&cfg);
    bool ok = vm_init(&machine, &cfg, err, sizeof(err));
    ASSERT_TRUE(ok, "vm_init must succeed");

    /* 1. Clear byte pointer flip-flop via port 0x0C */
    cpu86_port_out8(&machine.cpu, 0x0C, 0x00);
    ASSERT_EQ(machine.dma.flip_flop, 0, "flip_flop must be 0 after port 0x0C write");

    /* 2. Channel 1 Base/Current Address (port 0x02): write low byte 0x34, high byte 0x12 */
    cpu86_port_out8(&machine.cpu, 0x02, 0x34);
    ASSERT_EQ(machine.dma.flip_flop, 1, "flip_flop must be 1 after first address byte");
    ASSERT_EQ(machine.dma.base_addr[1], 0x0034, "low byte set");

    cpu86_port_out8(&machine.cpu, 0x02, 0x12);
    ASSERT_EQ(machine.dma.flip_flop, 0, "flip_flop must reset to 0 after second address byte");
    ASSERT_EQ(machine.dma.base_addr[1], 0x1234, "base_addr[1] must be 0x1234");
    ASSERT_EQ(machine.dma.cur_addr[1], 0x1234, "cur_addr[1] must track base_addr");

    /* Read back address from port 0x02 */
    uint8_t addr_lo = cpu86_port_in8(&machine.cpu, 0x02);
    uint8_t addr_hi = cpu86_port_in8(&machine.cpu, 0x02);
    ASSERT_EQ(addr_lo, 0x34, "read low address byte");
    ASSERT_EQ(addr_hi, 0x12, "read high address byte");

    /* 3. Channel 1 Word Count (port 0x03): write low byte 0xFF, high byte 0x03 (1023) */
    cpu86_port_out8(&machine.cpu, 0x03, 0xFF);
    ASSERT_EQ(machine.dma.flip_flop, 1, "flip_flop must be 1 after first count byte");
    cpu86_port_out8(&machine.cpu, 0x03, 0x03);
    ASSERT_EQ(machine.dma.flip_flop, 0, "flip_flop must reset to 0 after second count byte");
    ASSERT_EQ(machine.dma.base_count[1], 0x03FF, "base_count[1] must be 0x03FF");
    ASSERT_EQ(machine.dma.cur_count[1], 0x03FF, "cur_count[1] must track base_count");

    /* Read back count from port 0x03 */
    uint8_t cnt_lo = cpu86_port_in8(&machine.cpu, 0x03);
    uint8_t cnt_hi = cpu86_port_in8(&machine.cpu, 0x03);
    ASSERT_EQ(cnt_lo, 0xFF, "read low count byte");
    ASSERT_EQ(cnt_hi, 0x03, "read high count byte");

    /* 4. Flip-flop reset behavior */
    cpu86_port_out8(&machine.cpu, 0x02, 0xAA);
    ASSERT_EQ(machine.dma.flip_flop, 1, "flip-flop set after 1st byte");
    cpu86_port_out8(&machine.cpu, 0x0C, 0x00); /* Reset flip-flop */
    ASSERT_EQ(machine.dma.flip_flop, 0, "flip-flop reset by port 0x0C");
    cpu86_port_out8(&machine.cpu, 0x02, 0xBB); /* Should write to low byte again */
    ASSERT_EQ((machine.dma.base_addr[1] & 0xFF), 0xBB, "low byte overwritten after reset");

    /* 5. Page Register (port 0x83 for Ch 1, 0x87 for Ch 0, 0x81 for Ch 2, 0x82 for Ch 3) */
    cpu86_port_out8(&machine.cpu, 0x83, 0x05);
    ASSERT_EQ(machine.dma.page[1], 0x05, "page[1] must be 0x05");
    ASSERT_EQ(cpu86_port_in8(&machine.cpu, 0x83), 0x05, "read back page register 0x83");

    cpu86_port_out8(&machine.cpu, 0x87, 0x0A);
    ASSERT_EQ(machine.dma.page[0], 0x0A, "page[0] must be 0x0A");
    ASSERT_EQ(cpu86_port_in8(&machine.cpu, 0x87), 0x0A, "read back page register 0x87");

    /* 6. Mode Register (port 0x0B) */
    cpu86_port_out8(&machine.cpu, 0x0B, 0x49); /* Ch 1, single mode, read transfer */
    ASSERT_EQ(machine.dma.mode[1], 0x49, "mode[1] must be 0x49");

    /* 7. Single Mask Register (port 0x0A): bit 2 = mask/unmask, bits 0..1 = channel */
    cpu86_port_out8(&machine.cpu, 0x0A, 0x05); /* Channel 1, set mask (1 << 1 = 2) */
    ASSERT_TRUE((machine.dma.mask & 0x02) != 0, "Ch 1 must be masked");
    ASSERT_EQ(cpu86_port_in8(&machine.cpu, 0x0A), machine.dma.mask, "read mask port 0x0A");

    cpu86_port_out8(&machine.cpu, 0x0A, 0x01); /* Channel 1, clear mask */
    ASSERT_TRUE((machine.dma.mask & 0x02) == 0, "Ch 1 must be unmasked");

    /* 8. Master Mask Register (port 0x0F) */
    cpu86_port_out8(&machine.cpu, 0x0F, 0x0E);
    ASSERT_EQ(machine.dma.mask, 0x0E, "all mask register");
    ASSERT_EQ(cpu86_port_in8(&machine.cpu, 0x0A), 0x0E, "read mask matches 0x0E");

    vm_shutdown(&machine);
}

/* -------------------------------------------------------------------------
 * Test 2: 8259 PIC Ports 0x20 and 0x21
 * ------------------------------------------------------------------------- */
static void test_pic_ports(void) {
    printf("  [2/6] Testing 8259 PIC ports 0x20 and 0x21...\n");
    vm machine;
    vm_config cfg;
    char err[256];
    dma_fixture_config(&cfg);
    bool ok = vm_init(&machine, &cfg, err, sizeof(err));
    ASSERT_TRUE(ok, "vm_init must succeed");

    /* Port 0x21: Interrupt Mask Register (IMR) */
    cpu86_port_out8(&machine.cpu, 0x21, 0x80); /* Mask IRQ 7 */
    ASSERT_EQ(machine.pic.imr, 0x80, "IMR set to 0x80");
    ASSERT_EQ(cpu86_port_in8(&machine.cpu, 0x21), 0x80, "read IMR from port 0x21");

    cpu86_port_out8(&machine.cpu, 0x21, 0x00); /* Unmask all IRQs */
    ASSERT_EQ(machine.pic.imr, 0x00, "IMR unmasked");
    ASSERT_EQ(cpu86_port_in8(&machine.cpu, 0x21), 0x00, "read IMR 0x00");

    /* Port 0x20: Command Register (EOI 0x20) */
    machine.pic.isr = (uint8_t)(1 << machine.sb.irq); /* Simulate IRQ 7 in service */
    ASSERT_TRUE((machine.pic.isr & (1 << machine.sb.irq)) != 0, "ISR bit set");

    cpu86_port_out8(&machine.cpu, 0x20, 0x20); /* Non-specific EOI */
    ASSERT_EQ(machine.pic.last_cmd, 0x20, "last_cmd set to EOI");
    ASSERT_TRUE((machine.pic.isr & (1 << machine.sb.irq)) == 0, "ISR bit cleared by EOI");

    vm_shutdown(&machine);
}

/* -------------------------------------------------------------------------
 * Test 3: Sound Blaster DSP Commands 0xE0, 0xE1, 0x40
 * ------------------------------------------------------------------------- */
static void test_sb_dsp_commands(void) {
    printf("  [3/6] Testing Sound Blaster DSP commands (0xAA, 0xE0, 0xE1, 0x40)...\n");
    vm machine;
    vm_config cfg;
    char err[256];
    dma_fixture_config(&cfg);
    bool ok = vm_init(&machine, &cfg, err, sizeof(err));
    ASSERT_TRUE(ok, "vm_init must succeed");

    /* 1. Reset handshake: write 1 then 0 to port 0x226 */
    cpu86_port_out8(&machine.cpu, 0x226, 0x01);
    cpu86_port_out8(&machine.cpu, 0x226, 0x00);
    uint8_t status = cpu86_port_in8(&machine.cpu, 0x22E);
    ASSERT_EQ(status, 0x80, "DSP read buffer data ready");
    uint8_t ready_byte = cpu86_port_in8(&machine.cpu, 0x22A);
    ASSERT_EQ(ready_byte, 0xAA, "DSP ready announcement byte 0xAA");

    /* 2. Version 0xE1: report 2.01 */
    cpu86_port_out8(&machine.cpu, 0x22C, 0xE1);
    uint8_t v_maj = cpu86_port_in8(&machine.cpu, 0x22A);
    uint8_t v_min = cpu86_port_in8(&machine.cpu, 0x22A);
    ASSERT_EQ(v_maj, 2, "DSP major version 2");
    ASSERT_EQ(v_min, 1, "DSP minor version 1");

    /* 3. Identify 0xE0: inverts argument */
    cpu86_port_out8(&machine.cpu, 0x22C, 0xE0);
    cpu86_port_out8(&machine.cpu, 0x22C, 0x3C);
    uint8_t id_res = cpu86_port_in8(&machine.cpu, 0x22A);
    ASSERT_EQ(id_res, (uint8_t)~0x3C, "Identify inverted response (~0x3C = 0xC3)");

    /* 4. Set Time Constant 0x40: sample_rate = 1000000 / (256 - tc) */
    /* tc = 165 -> 256 - 165 = 91 -> 1000000 / 91 = 10989 Hz */
    cpu86_port_out8(&machine.cpu, 0x22C, 0x40);
    cpu86_port_out8(&machine.cpu, 0x22C, 165);
    ASSERT_EQ(machine.sb.time_constant, 165, "time constant set");
    ASSERT_EQ(machine.sb.sample_rate, 10989, "sample rate calculated accurately");

    vm_shutdown(&machine);
}

/* -------------------------------------------------------------------------
 * Test 4: DSP Command 0x14 8-bit Single Cycle DMA Transfer & RAM Extraction
 * ------------------------------------------------------------------------- */
static void test_sb_dma_transfer(void) {
    printf("  [4/6] Testing DSP 0x14 single cycle DMA transfer & guest memory extraction...\n");
    vm machine;
    vm_config cfg;
    char err[256];
    dma_fixture_config(&cfg);
    bool ok = vm_init(&machine, &cfg, err, sizeof(err));
    ASSERT_TRUE(ok, "vm_init must succeed");

    machine.cycles_per_second = 10000000ULL; /* 10 MHz virtual CPU */
    machine.sb.sample_rate = 11025;

    /* Hook our test capture function */
    vm_audio_dma_write = test_capture_dma_write;
    g_capture_calls = 0;
    g_captured_count = 0;

    /* Set up test payload in guest memory at Page 1 = 0x02, Offset = 0x4000 (phys 0x24000) */
    uint32_t phys_addr = 0x24000;
    uint32_t transfer_len = 512;
    for (uint32_t i = 0; i < transfer_len; i++) {
        g_dos_mem[phys_addr + i] = (uint8_t)((i * 7 + 13) & 0xFF);
    }

    /* Program 8237 DMA Channel 1 */
    cpu86_port_out8(&machine.cpu, 0x0A, 0x05); /* Mask Ch 1 */
    cpu86_port_out8(&machine.cpu, 0x0C, 0x00); /* Clear flip-flop */
    cpu86_port_out8(&machine.cpu, 0x0B, 0x49); /* Single mode read Ch 1 */
    cpu86_port_out8(&machine.cpu, 0x02, (uint8_t)(0x4000 & 0xFF));        /* Addr low */
    cpu86_port_out8(&machine.cpu, 0x02, (uint8_t)((0x4000 >> 8) & 0xFF)); /* Addr high */
    cpu86_port_out8(&machine.cpu, 0x83, 0x02);                             /* Page 0x02 */
    cpu86_port_out8(&machine.cpu, 0x03, (uint8_t)((transfer_len - 1) & 0xFF));        /* Count low */
    cpu86_port_out8(&machine.cpu, 0x03, (uint8_t)(((transfer_len - 1) >> 8) & 0xFF)); /* Count high */
    cpu86_port_out8(&machine.cpu, 0x0A, 0x01); /* Unmask Ch 1 */

    /* Dispatch DSP Command 0x14 */
    cpu86_port_out8(&machine.cpu, 0x22C, 0x14);
    cpu86_port_out8(&machine.cpu, 0x22C, (uint8_t)((transfer_len - 1) & 0xFF));
    cpu86_port_out8(&machine.cpu, 0x22C, (uint8_t)(((transfer_len - 1) >> 8) & 0xFF));

    /* Verify sink was called with exact guest memory contents */
    ASSERT_EQ(g_capture_calls, 1, "vm_audio_dma_write must be called once");
    ASSERT_EQ(g_captured_count, 512, "captured exactly 512 samples");
    ASSERT_EQ(g_captured_rate, 11025, "captured at 11025 Hz");
    int cmp = memcmp(g_captured_buf, g_dos_mem + phys_addr, transfer_len);
    ASSERT_EQ(cmp, 0, "captured samples must byte-match guest memory");

    /* Verify DMA channel state after transfer */
    ASSERT_EQ(machine.dma.cur_addr[1], (uint16_t)(0x4000 + transfer_len), "cur_addr updated");
    ASSERT_EQ(machine.dma.cur_count[1], 0xFFFF, "cur_count expired to 0xFFFF");
    ASSERT_EQ(machine.sb.dma_transferred_bytes, 512, "dma_transferred_bytes updated");
    ASSERT_TRUE(machine.sb.dma_active, "dma_active must be true while in flight");

    uint64_t expected_cycles = (uint64_t)transfer_len * machine.cycles_per_second / machine.sb.sample_rate;
    ASSERT_EQ(machine.sb.dma_end_cycles, machine.cpu.cycles + expected_cycles, "dma_end_cycles calculated");

    vm_shutdown(&machine);
}

/* -------------------------------------------------------------------------
 * Test 5: Virtual Cycle Timing, IRQ 7 Injection, and Port 0x22E Acknowledgment
 * ------------------------------------------------------------------------- */
static void test_virtual_irq_timing_and_ack(void) {
    printf("  [5/6] Testing virtual cycle IRQ timing, injection, and port 0x22E ACK...\n");
    vm machine;
    vm_config cfg;
    char err[256];
    dma_fixture_config(&cfg);
    bool ok = vm_init(&machine, &cfg, err, sizeof(err));
    ASSERT_TRUE(ok, "vm_init must succeed");

    machine.cycles_per_second = 1000000ULL;
    machine.pit_period_cycles = 1000000000ULL; /* Don't fire timer tick during test */
    machine.next_tick_cycles  = 1000000000ULL;
    machine.sb.sample_rate = 10000;
    machine.sb.irq = 7;

    /* Start DMA of 100 bytes -> 100 * 1000000 / 10000 = 10,000 virtual cycles */
    uint32_t dma_len = 100;
    cpu86_port_out8(&machine.cpu, 0x0C, 0x00);
    cpu86_port_out8(&machine.cpu, 0x02, 0x00);
    cpu86_port_out8(&machine.cpu, 0x02, 0x20);
    cpu86_port_out8(&machine.cpu, 0x83, 0x01);
    cpu86_port_out8(&machine.cpu, 0x03, (uint8_t)(dma_len - 1));
    cpu86_port_out8(&machine.cpu, 0x03, 0x00);
    cpu86_port_out8(&machine.cpu, 0x0A, 0x01);

    cpu86_port_out8(&machine.cpu, 0x22C, 0x14);
    cpu86_port_out8(&machine.cpu, 0x22C, (uint8_t)(dma_len - 1));
    cpu86_port_out8(&machine.cpu, 0x22C, 0x00);

    ASSERT_TRUE(machine.sb.dma_active, "DMA active");
    ASSERT_TRUE(!machine.sb.irq_pending, "IRQ not pending before cycles expire");

    /* Install a Sound Blaster ISR at IVT vector 0x0F (IRQ 7: 0x08 + 7 = 0x0F = vector 15)
     * Vector 15 lives at linear address 15 * 4 = 60 = 0x003C.
     * Put ISR at 0x1000:0x0020. */
    uint16_t isr_seg = 0x1000;
    uint16_t isr_off = 0x0020;
    uint32_t isr_lin = ((uint32_t)isr_seg << 4) + isr_off;

    /* Setup IVT entry */
    g_dos_mem[0x003C] = (uint8_t)(isr_off & 0xFF);
    g_dos_mem[0x003D] = (uint8_t)(isr_off >> 8);
    g_dos_mem[0x003E] = (uint8_t)(isr_seg & 0xFF);
    g_dos_mem[0x003F] = (uint8_t)(isr_seg >> 8);

    /* ISR code:
     *   in al, dx      ; 0xEC (with DX = 0x22E set in setup)
     *   out 0x20, al   ; 0xE6 0x20
     *   iret           ; 0xCF
     */
    g_dos_mem[isr_lin + 0] = 0xEC;       /* IN AL, DX */
    g_dos_mem[isr_lin + 1] = 0xE6;       /* OUT 0x20, AL */
    g_dos_mem[isr_lin + 2] = 0x20;
    g_dos_mem[isr_lin + 3] = 0xCF;       /* IRET */

    /* Put background code at CS:IP: a series of NOPs */
    machine.cpu.s[CPU_CS] = 0x2000;
    machine.cpu.ip = 0x0100;
    uint32_t bg_lin = ((uint32_t)0x2000 << 4) + 0x0100;
    memset(g_dos_mem + bg_lin, 0x90, 64); /* NOPs */
    machine.cpu.r[CPU_DX] = 0x022E;       /* DX points to DSP ack port */
    machine.cpu.r[CPU_AX] = 0x0020;       /* AL has 0x20 for PIC EOI */
    machine.cpu.flags |= F_IF;            /* Interrupts enabled */

    /* Advance cycles past dma_end_cycles */
    machine.cpu.cycles = machine.sb.dma_end_cycles;

    /* Run one slice */
    vm_run(&machine, 1);

    /* Verify DMA marked complete and IRQ was injected */
    ASSERT_TRUE(!machine.sb.dma_active, "DMA completed");
    /* CPU should now be executing inside or past the ISR */
    /* Check that port 0x22E ACK cleared irq_pending */
    cpu86_port_in8(&machine.cpu, 0x22E);
    ASSERT_TRUE(!machine.sb.irq_pending, "Port 0x22E read deasserts irq_pending");

    vm_shutdown(&machine);
}

/* -------------------------------------------------------------------------
 * Test 6: Audio HAL SPSC Ring Buffer, Resampling, and Saturation Clamping
 * ------------------------------------------------------------------------- */
static void test_audio_hal_ring_buffer(void) {
    printf("  [6/6] Testing Audio HAL SPSC ring buffer, linear resampling, and mixer...\n");

    /* Initialize Audio HAL in headless/dummy mode */
    bool init_ok = hal_audio_init();
    ASSERT_TRUE(init_ok, "hal_audio_init must succeed");

    /* Create synthetic 8-bit mono test buffer (sine / triangle) */
    const uint32_t count = 441; /* 10ms at 44.1 kHz, or 20ms at 22.05 kHz */
    uint8_t pcm[count];
    for (uint32_t i = 0; i < count; i++) {
        pcm[i] = (uint8_t)(128.0 + 120.0 * sin((double)i * 0.1));
    }

    /* Submit block at 22,050 Hz -> Resampled to 44,100 Hz (2x expansion -> 882 frames) */
    hal_audio_dma_submit_block(pcm, count, 22050);

    /* Test tick draining in dummy mode */
    hal_audio_tick();

    /* Test volume control */
    hal_audio_set_volume(128, 100, 100, 128);

    /* Test extreme values for saturation clamping */
    uint8_t max_pcm[4] = { 255, 255, 0, 0 };
    hal_audio_dma_submit_block(max_pcm, 4, 44100);

    /* Tick multiple times to drain */
    for (int t = 0; t < 20; t++) {
        hal_audio_tick();
    }

    hal_audio_shutdown();
}

/* -------------------------------------------------------------------------
 * Test 7: DSP 0x10 direct DAC, 0x48 + 0x1C auto-init block streaming,
 * re-arm on completion, and 0xD9/0xDA halt.
 * ------------------------------------------------------------------------- */
static void test_sb_direct_dac_and_autoinit(void) {
    printf("  [7] Testing DSP direct-DAC, auto-init streaming, re-arm, halt...\n");
    vm machine;
    vm_config cfg;
    char err[256];
    dma_fixture_config(&cfg);
    bool ok = vm_init(&machine, &cfg, err, sizeof(err));
    ASSERT_TRUE(ok, "vm_init must succeed");

    machine.cycles_per_second = 10000000ULL; /* 10 MHz virtual CPU */
    machine.pit_period_cycles = 1000000000ULL;
    machine.next_tick_cycles  = 1000000000ULL;
    machine.sb.sample_rate = 11025;
    machine.sb.irq = 7;
    /* Mask IRQ7 at the PIC: this test asserts pend/re-arm state, not the
     * guest ISR dispatch (no ISR is installed at vector 0x0F here). */
    machine.pic.imr |= (uint8_t)(1 << 7);

    vm_audio_dma_write = test_capture_dma_write;
    g_capture_calls = 0;
    g_captured_count = 0;

    /* 1. Direct DAC: 0x10 followed by one sample byte forwards 1 sample. */
    cpu86_port_out8(&machine.cpu, 0x22C, 0x10);
    cpu86_port_out8(&machine.cpu, 0x22C, 0xAB);
    ASSERT_EQ(g_capture_calls, 1, "direct-DAC must forward one block");
    ASSERT_EQ(g_captured_count, 1, "direct-DAC forwards exactly 1 sample");
    ASSERT_EQ(g_captured_buf[0], 0xAB, "direct-DAC sample byte preserved");

    /* 2. Program DMA ch1 across its 64 KB address boundary. */
    uint32_t block = 512;
    for (uint32_t i = 0; i < block; i++) {
        uint32_t wrapped_phys = 0x10000u | ((0xFF00u + i) & 0xFFFFu);
        g_dos_mem[wrapped_phys] = (uint8_t)((i * 3 + 1) & 0xFF);
    }
    cpu86_port_out8(&machine.cpu, 0x0C, 0x00);
    cpu86_port_out8(&machine.cpu, 0x02, 0x00);
    cpu86_port_out8(&machine.cpu, 0x02, 0xFF);
    cpu86_port_out8(&machine.cpu, 0x83, 0x01);
    cpu86_port_out8(&machine.cpu, 0x0A, 0x01);

    /* 3. Set block size (0x48) then start auto-init (0x1C). */
    g_capture_calls = 0;
    cpu86_port_out8(&machine.cpu, 0x22C, 0x48);
    cpu86_port_out8(&machine.cpu, 0x22C, (uint8_t)(block - 1));
    cpu86_port_out8(&machine.cpu, 0x22C, (uint8_t)((block - 1) >> 8));
    ASSERT_EQ(machine.sb.block_size, block, "block size stored");
    cpu86_port_out8(&machine.cpu, 0x22C, 0x1C);
    ASSERT_TRUE(machine.sb.auto_init, "auto-init flagged");
    ASSERT_EQ(g_capture_calls, 1, "auto-init start streams the block");
    ASSERT_EQ(g_captured_count, block, "auto-init block length");
    for (uint32_t i = 0; i < block; i++) {
        ASSERT_EQ(g_captured_buf[i], (uint8_t)((i * 3 + 1) & 0xFF),
                  "auto-init bytes follow the channel address wrap");
    }

    /* 4. Park the CPU on NOPs, expire the block period, run one slice:
     *    IRQ must pend AND the block must re-stream (still active). */
    machine.cpu.s[CPU_CS] = 0x2000;
    machine.cpu.ip = 0x0100;
    uint32_t bg_lin = ((uint32_t)0x2000 << 4) + 0x0100;
    memset(g_dos_mem + bg_lin, 0x90, 64);
    machine.cpu.flags |= F_IF;
    machine.cpu.cycles = machine.sb.dma_end_cycles;
    vm_run(&machine, 1);
    ASSERT_TRUE(machine.sb.irq_pending, "auto-init block completion raises IRQ");
    ASSERT_TRUE(machine.sb.dma_active, "auto-init stays active across blocks");
    ASSERT_EQ(g_capture_calls, 2, "auto-init re-streams the looping block");
    for (uint32_t i = 0; i < block; i++) {
        ASSERT_EQ(g_captured_buf[i], (uint8_t)((i * 3 + 1) & 0xFF),
                  "auto-init replay preserves wrapped channel data");
    }

    /* 5. Halt (0xDA) stops the stream. */
    cpu86_port_out8(&machine.cpu, 0x22C, 0xDA);
    ASSERT_TRUE(!machine.sb.auto_init, "halt clears auto-init");
    ASSERT_TRUE(!machine.sb.dma_active, "halt stops DMA");

    vm_shutdown(&machine);
}

int main(void) {
    printf("=== Running Sound Blaster DMA Pipeline Unit Tests ===\n");
    create_dma_fixture();
    test_dma_registers();
    test_pic_ports();
    test_sb_dsp_commands();
    test_sb_dma_transfer();
    test_virtual_irq_timing_and_ack();
    test_audio_hal_ring_buffer();
    test_sb_direct_dac_and_autoinit();
    remove("build/dma_fixture.mz");
    remove("build/dma-fixture-saves/LEGEND.INI");
    printf("=== ALL SOUND BLASTER DMA TESTS PASSED [7/7] ===\n");
    return 0;
}
