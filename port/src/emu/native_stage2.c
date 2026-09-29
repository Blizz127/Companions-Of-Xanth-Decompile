/*
 * Stage 2 native units: adapters around recovered game C.
 *
 * These functions are installed only at executable offsets whose pinned
 * XANBUD bytes were rebuilt and matched by tools/verify.py. The adapter maps
 * the guest's 16-bit far-call ABI and data segment onto the host build; the
 * function body itself is included directly from the recovered source.
 */
#include "native_stage2.h"

#include <stdint.h>

#define far
#include "../../../src/set_int_and_zero.c"
#undef far
#define far
#include "../../../src/set_far_ptr.c"
#undef far

#define SET_INT_AND_ZERO_EXE_OFFSET 17820u
#define G_VAL_DS_OFFSET             0x5812u
#define G_ZERO_DS_OFFSET            0x5814u
#define SET_FAR_PTR_EXE_OFFSET      83182u
#define G_FAR_PTR_OFFSET            0x62d8u

typedef struct {
    uint16_t offset;
    uint16_t segment;
} xanth_guest_far_pointer;

static uint64_t g_set_int_and_zero_hits;
static uint64_t g_set_far_ptr_hits;
static xanth_guest_far_pointer g_far_ptr_scratch;

static hook_result_t native_set_int_and_zero(cpu86 *cpu, void *user) {
    uint16_t arg = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4));
    vm *machine = (vm *)cpu->vm;

    if (cpu->step_budget_remaining < 7u) return HOOK_CONTINUE;

    /* Keep every guest instruction boundary at which the VM can inject work. */
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 28u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 28u)))
            return HOOK_CONTINUE;
    }

    /*
     * Recovered code reads arg at BP+6, writes AX to DS:5812, writes zero
     * to DS:5814, restores BP, and RETF. The native C call performs those
     * same writes in host globals; copy the resulting words back to the
     * guest DS and reproduce AX/RETF. Its seven instructions cost 28 cycles
     * under cpu86's current four-cycle instruction model.
     */
    set_int_and_zero((int16_t)arg);
    seg_w16(cpu->s[CPU_DS], G_VAL_DS_OFFSET, (uint16_t)g_val);
    seg_w16(cpu->s[CPU_DS], G_ZERO_DS_OFFSET, (uint16_t)g_zero);
    cpu->r[CPU_AX] = arg;
    cpu->cycles += 7u * 4u;
    cpu->step_guest_insns = 7;
    g_set_int_and_zero_hits++;
    return HOOK_DID_RETF;
}

static hook_result_t native_set_far_ptr(cpu86 *cpu, void *user) {
    uint16_t pointer_offset = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4));
    uint16_t pointer_segment = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 6));
    vm *machine = (vm *)cpu->vm;

    if (cpu->step_budget_remaining < 8u) return HOOK_CONTINUE;

    /* Keep every guest instruction boundary at which the VM can inject work. */
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 32u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 32u)))
            return HOOK_CONTINUE;
    }

    /* Map the guest 16:16 value into a host object for the recovered C body. */
    g_far_ptr_scratch.offset = pointer_offset;
    g_far_ptr_scratch.segment = pointer_segment;
    set_far_ptr(&g_far_ptr_scratch);
    {
        const xanth_guest_far_pointer *stored = (const xanth_guest_far_pointer *)g;
        seg_w16(cpu->s[CPU_DS], G_FAR_PTR_OFFSET, stored->offset);
        seg_w16(cpu->s[CPU_DS], (uint16_t)(G_FAR_PTR_OFFSET + 2), stored->segment);
    }
    cpu->r[CPU_AX] = pointer_offset;
    cpu->r[CPU_DX] = pointer_segment;
    cpu->cycles += 8u * 4u;
    cpu->step_guest_insns = 8;
    g_set_far_ptr_hits++;
    return HOOK_DID_RETF;
}

bool xanth_native_stage2_install(vm *machine) {
    static const uint8_t verified_body[] = {
        0x55, 0x8b, 0xec, 0x8b, 0x46, 0x06, 0xa3, 0x12, 0x58,
        0xc7, 0x06, 0x14, 0x58, 0x00, 0x00, 0x5d, 0xcb
    };
    static const uint8_t verified_far_ptr_body[] = {
        0x55, 0x8b, 0xec, 0x8b, 0x46, 0x06, 0x8b, 0x56, 0x08,
        0xa3, 0xd8, 0x62, 0x89, 0x16, 0xda, 0x62, 0x5d, 0xcb
    };
    uint32_t linear;
    uint16_t segment, offset;
    if (!machine) return false;

    for (size_t i = 0; i < sizeof(verified_body); i++) {
        if (seg_r8(machine->img.load_seg,
                   (uint16_t)(SET_INT_AND_ZERO_EXE_OFFSET + i)) != verified_body[i])
            return false;
    }

    for (size_t i = 0; i < sizeof(verified_far_ptr_body); i++) {
        uint32_t address = (uint32_t)machine->img.load_seg * 16u +
                           SET_FAR_PTR_EXE_OFFSET + (uint32_t)i;
        uint8_t actual = mem_r8(address);
        if (actual != verified_far_ptr_body[i]) {
            return false;
        }
    }

    linear = (uint32_t)machine->img.load_seg * 16u + SET_INT_AND_ZERO_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_set_int_and_zero_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_set_int_and_zero, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + SET_FAR_PTR_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_set_far_ptr_hits = 0;
    return cpu86_hook_install(segment, offset, native_set_far_ptr, NULL);
}

uint64_t xanth_native_set_int_and_zero_hits(void) {
    return g_set_int_and_zero_hits;
}

uint64_t xanth_native_set_far_ptr_hits(void) {
    return g_set_far_ptr_hits;
}
