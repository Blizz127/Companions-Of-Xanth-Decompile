/*
 * Stage 2 native units: adapters around recovered game C.
 *
 * These functions are installed only at executable offsets whose pinned
 * XANBUD bytes were rebuilt and matched by tools/verify.py. The adapter maps
 * the guest's 16-bit far-call ABI and data segment onto the host build; the
 * function body itself is included directly from the recovered source.
 */
#include "native_stage2.h"
#include "cpu86_alu.h"

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
#define EXE_94712_EXE_OFFSET        94712u
#define IF0_HELPER_INC_EXE_OFFSET   16216u
#define IF0_HELPER_INC_G_DS_OFFSET  0x69bau
#define EXE_14360_EXE_OFFSET        14360u
#define EXE_14360_TBL_DS_OFFSET     0x56a5u
#define SET_FAR_ARR_EXE_OFFSET      83200u
#define SET_FAR_ARR_DS_OFFSET       0x4264u
#define GET_FAR_IDX_EXE_OFFSET      102352u
#define GET_FAR_IDX_GLOBAL_DS_OFFSET 0x67bau
#define EXE_37625_A_OFFSET           99835u
#define EXE_37625_B_OFFSET           99897u
#define EXE_37625_GLOBAL_DS_OFFSET   0x4ea0u
#define EXE_99679_EXE_OFFSET         99679u
#define EXE_99679_COUNTER_DS_OFFSET  0x4f28u
#define EXE_99679_TABLE_DS_OFFSET    0x4f2au

typedef struct {
    uint16_t offset;
    uint16_t segment;
} xanth_guest_far_pointer;

static uint64_t g_set_int_and_zero_hits;
static uint64_t g_set_far_ptr_hits;
static uint64_t g_exe_94712_hits;
static uint64_t g_if0_helper_inc_hits;
static uint64_t g_exe_14360_hits;
static uint64_t g_set_far_arr_hits;
static uint64_t g_get_far_idx_hits;
static uint64_t g_exe_37625_hits;
static uint64_t g_exe_99679_hits;
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

/* Portable lowering of the exact instruction sequence in src/exe_94712.c. */
static hook_result_t native_exe_94712(cpu86 *cpu, void *user) {
    uint16_t ax = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4));
    uint16_t dx = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 6));
    uint16_t addend_ax = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 8));
    uint16_t addend_dx = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 10));
    vm *machine = (vm *)cpu->vm;

    if (cpu->step_budget_remaining < 19u) return HOOK_CONTINUE;

    /* The listing is 19 instructions / 76 modeled cycles including its frame. */
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 76u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 76u)))
            return HOOK_CONTINUE;
    }

    /* add ax,ax; adc dx,dx; four adc pairs, then the final adc ax,ax. */
    ax = alu_op(cpu, ALU_ADD, ax, ax, 16);
    dx = alu_op(cpu, ALU_ADC, dx, dx, 16);
    for (int i = 0; i < 3; i++) {
        ax = alu_op(cpu, ALU_ADC, ax, ax, 16);
        dx = alu_op(cpu, ALU_ADC, dx, dx, 16);
    }
    ax = alu_op(cpu, ALU_ADC, ax, ax, 16);

    /* xchg ax,dx; and dx,0xF; add ax,[bp+0xa]; adc dx,[bp+0xc]. */
    {
        uint16_t tmp = ax;
        ax = dx;
        dx = tmp;
    }
    dx = alu_op(cpu, ALU_AND, dx, 0x000fu, 16);
    ax = alu_op(cpu, ALU_ADD, ax, addend_ax, 16);
    dx = alu_op(cpu, ALU_ADC, dx, addend_dx, 16);

    cpu->r[CPU_AX] = ax;
    cpu->r[CPU_DX] = dx;
    cpu->cycles += 19u * 4u;
    cpu->step_guest_insns = 19;
    g_exe_94712_hits++;
    return HOOK_DID_RETF;
}

/*
 * Recovered src/if0_helper_inc.c has two paths.  When its DS global g is
 * zero, it calls an unresolved far helper and increments g; keep that path
 * in the interpreter.  Once g is nonzero, the exact retail path is
 * `cmp word ptr ds:[69BAh],0; jne +9; retf`, so lower just that verified
 * three-instruction fast return.  This entry is exceptionally hot during
 * boot (over five million calls) and the slow branch remains untouched.
 */
static hook_result_t native_if0_helper_inc_nonzero(cpu86 *cpu, void *user) {
    vm *machine = (vm *)cpu->vm;
    uint16_t value;

    if (cpu->step_budget_remaining < 3u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 12u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 12u)))
            return HOOK_CONTINUE;
    }

    value = seg_r16(cpu->s[CPU_DS], IF0_HELPER_INC_G_DS_OFFSET);
    if (value == 0) return HOOK_CONTINUE;

    /* cmp [g],0 sets the same arithmetic flags; JNZ and RETF preserve them. */
    (void)alu_op(cpu, ALU_CMP, value, 0, 16);
    cpu->cycles += 3u * 4u;
    cpu->step_guest_insns = 3;
    g_if0_helper_inc_hits++;
    return HOOK_DID_RETF;
}

/* Portable lowering of recovered src/exe_14360.c. */
static hook_result_t native_exe_14360(cpu86 *cpu, void *user) {
    uint16_t arg = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4));
    uint16_t table_offset = (uint16_t)(EXE_14360_TBL_DS_OFFSET + arg);
    uint8_t bit = seg_r8(cpu->s[CPU_DS], table_offset);
    uint16_t instruction_count = (bit & 1u) ? 9u : 8u;
    vm *machine = (vm *)cpu->vm;

    if (cpu->step_budget_remaining < instruction_count) return HOOK_CONTINUE;
    if (machine) {
        uint64_t edge_cycles = (uint64_t)instruction_count * 4u;
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= edge_cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= edge_cycles)))
            return HOOK_CONTINUE;
    }

    /* TEST r/m8,1; JZ; then LEA or MOV sets only the return value. */
    (void)alu_op(cpu, ALU_AND, bit, 1u, 8);
    cpu->r[CPU_BX] = arg;
    cpu->r[CPU_AX] = (uint16_t)(arg + ((bit & 1u) ? 0x20u : 0u));
    cpu->cycles += (uint64_t)instruction_count * 4u;
    cpu->step_guest_insns = (uint8_t)instruction_count;
    g_exe_14360_hits++;
    return HOOK_DID_RETF;
}

/* Portable lowering of recovered src/set_far_arr.c; array data stays guest-owned. */
static hook_result_t native_set_far_arr(cpu86 *cpu, void *user) {
    uint16_t index = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4));
    uint16_t pointer_offset = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 6));
    uint16_t pointer_segment = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 8));
    vm *machine = (vm *)cpu->vm;

    if (cpu->step_budget_remaining < 11u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 44u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 44u)))
            return HOOK_CONTINUE;
    }

    /* Two ADD BX,BX instructions compute the guest's 16-bit index * 4. */
    index = alu_op(cpu, ALU_ADD, index, index, 16);
    index = alu_op(cpu, ALU_ADD, index, index, 16);
    {
        uint16_t slot = (uint16_t)(SET_FAR_ARR_DS_OFFSET + index);
        seg_w16(cpu->s[CPU_DS], slot, pointer_offset);
        seg_w16(cpu->s[CPU_DS], (uint16_t)(slot + 2u), pointer_segment);
    }

    cpu->r[CPU_AX] = pointer_offset;
    cpu->r[CPU_DX] = pointer_segment;
    cpu->r[CPU_BX] = index;
    cpu->cycles += 11u * 4u;
    cpu->step_guest_insns = 11;
    g_set_far_arr_hits++;
    return HOOK_DID_RETF;
}

/* Portable lowering of recovered src/get_far_idx.c against guest far memory. */
static hook_result_t native_get_far_idx(cpu86 *cpu, void *user) {
    uint8_t arg = seg_r8(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4));
    uint16_t index = arg;
    uint16_t array_offset, array_segment, slot;
    uint16_t result_offset, result_segment;
    vm *machine = (vm *)cpu->vm;

    if (cpu->step_budget_remaining < 14u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 56u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 56u)))
            return HOOK_CONTINUE;
    }

    /* SUB BH,BH zero extends the byte index; the two ADDs scale by 4. */
    (void)alu_op(cpu, ALU_SUB, (uint8_t)(cpu->r[CPU_BX] >> 8),
                 (uint8_t)(cpu->r[CPU_BX] >> 8), 8);
    index = alu_op(cpu, ALU_ADD, index, index, 16);
    index = alu_op(cpu, ALU_ADD, index, index, 16);

    array_offset = seg_r16(cpu->s[CPU_DS], GET_FAR_IDX_GLOBAL_DS_OFFSET);
    array_segment = seg_r16(cpu->s[CPU_DS],
                            (uint16_t)(GET_FAR_IDX_GLOBAL_DS_OFFSET + 2u));
    slot = (uint16_t)(array_offset + index);
    result_offset = seg_r16(array_segment, slot);
    result_segment = seg_r16(array_segment, (uint16_t)(slot + 2u));

    cpu->r[CPU_BX] = index;
    cpu->s[CPU_ES] = array_segment;
    cpu->r[CPU_AX] = result_offset;
    cpu->r[CPU_DX] = result_segment;
    cpu->cycles += 14u * 4u;
    cpu->step_guest_insns = 14;
    g_get_far_idx_hits++;
    return HOOK_DID_RETF;
}

/* Recovered src/exe_37625.c is a DS word clear followed by a far return. */
static hook_result_t native_exe_37625(cpu86 *cpu, void *user) {
    vm *machine = (vm *)cpu->vm;
    if (cpu->step_budget_remaining < 2u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 8u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 8u)))
            return HOOK_CONTINUE;
    }

    seg_w16(cpu->s[CPU_DS], EXE_37625_GLOBAL_DS_OFFSET, 0);
    cpu->cycles += 2u * 4u;
    cpu->step_guest_insns = 2;
    g_exe_37625_hits++;
    return HOOK_DID_RETF;
}

/* Portable lowering of recovered src/exe_99679.c and its guest DS globals. */
static hook_result_t native_exe_99679(cpu86 *cpu, void *user) {
    uint16_t arg = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4));
    uint16_t counter = seg_r16(cpu->s[CPU_DS], EXE_99679_COUNTER_DS_OFFSET);
    uint16_t test_result;
    uint16_t instruction_count;
    vm *machine = (vm *)cpu->vm;

    /* The original A0 loads only AL; AND AX,1 then clears the stale AH. */
    test_result = alu_op(cpu, ALU_AND,
                         (uint16_t)((cpu->r[CPU_AX] & 0xff00u) | (counter & 0xffu)),
                         1u, 16);
    (void)alu_op(cpu, ALU_CMP, test_result, arg, 16);
    if (cpu->flags & F_ZF) {
        uint16_t table_byte = (uint16_t)(EXE_99679_TABLE_DS_OFFSET + counter);
        instruction_count = 12u;
        if (cpu->step_budget_remaining < instruction_count) return HOOK_CONTINUE;
        if (machine) {
            uint64_t edge_cycles = (uint64_t)instruction_count * 4u;
            uint64_t next_tick = machine->next_tick_cycles;
            uint64_t dma_end = machine->sb.dma_end_cycles;
            if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
                next_tick - cpu->cycles <= edge_cycles ||
                (machine->sb.dma_active &&
                 (dma_end <= cpu->cycles || dma_end - cpu->cycles <= edge_cycles)))
                return HOOK_CONTINUE;
        }
        cpu->r[CPU_BX] = counter;
        {
            uint8_t next = (uint8_t)alu_inc(cpu, seg_r8(cpu->s[CPU_DS], table_byte), 8);
            seg_w8(cpu->s[CPU_DS], table_byte, next);
        }
    } else {
        (void)alu_op(cpu, ALU_CMP, counter, 0x000fu, 16);
        if ((cpu->flags & F_CF) == 0) {
            instruction_count = 11u;
            if (cpu->step_budget_remaining < instruction_count) return HOOK_CONTINUE;
            if (machine) {
                uint64_t edge_cycles = (uint64_t)instruction_count * 4u;
                uint64_t next_tick = machine->next_tick_cycles;
                uint64_t dma_end = machine->sb.dma_end_cycles;
                if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
                    next_tick - cpu->cycles <= edge_cycles ||
                    (machine->sb.dma_active &&
                     (dma_end <= cpu->cycles || dma_end - cpu->cycles <= edge_cycles)))
                    return HOOK_CONTINUE;
            }
            /* `cmp g,15; jnb` returns with the original BX and compare flags. */
        } else {
            instruction_count = 14u;
            if (cpu->step_budget_remaining < instruction_count) return HOOK_CONTINUE;
            if (machine) {
                uint64_t edge_cycles = (uint64_t)instruction_count * 4u;
                uint64_t next_tick = machine->next_tick_cycles;
                uint64_t dma_end = machine->sb.dma_end_cycles;
                if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
                    next_tick - cpu->cycles <= edge_cycles ||
                    (machine->sb.dma_active &&
                     (dma_end <= cpu->cycles || dma_end - cpu->cycles <= edge_cycles)))
                    return HOOK_CONTINUE;
            }
            counter = alu_inc(cpu, counter, 16);
            seg_w16(cpu->s[CPU_DS], EXE_99679_COUNTER_DS_OFFSET, counter);
            cpu->r[CPU_BX] = counter;
            seg_w8(cpu->s[CPU_DS],
                   (uint16_t)(EXE_99679_TABLE_DS_OFFSET + counter), 1u);
        }
    }

    /* The body preserves the AND result in AX even when g changes. */
    cpu->r[CPU_AX] = test_result;
    cpu->cycles += (uint64_t)instruction_count * 4u;
    cpu->step_guest_insns = (uint8_t)instruction_count;
    g_exe_99679_hits++;
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
    static const uint8_t verified_exe_94712_body[] = {
        0x55, 0x8b, 0xec, 0x8b, 0x46, 0x06, 0x8b, 0x56, 0x08,
        0x03, 0xc0, 0x13, 0xd2, 0x13, 0xc0, 0x13, 0xd2, 0x13, 0xc0,
        0x13, 0xd2, 0x13, 0xc0, 0x13, 0xd2, 0x13, 0xc0, 0x92, 0x83,
        0xe2, 0x0f, 0x03, 0x46, 0x0a, 0x13, 0x56, 0x0c, 0x5d, 0xcb
    };
    static const uint8_t verified_if0_helper_inc_fast_prefix[] = {
        0x83, 0x3e, 0xba, 0x69, 0x00, 0x75, 0x09
    };
    static const uint8_t verified_exe_14360_body[] = {
        0x55, 0x8b, 0xec, 0x8b, 0x5e, 0x06, 0xf6, 0x87, 0xa5, 0x56,
        0x01, 0x74, 0x05, 0x8d, 0x47, 0x20, 0xeb, 0x02, 0x8b, 0xc3,
        0x5d, 0xcb
    };
    static const uint8_t verified_set_far_arr_body[] = {
        0x55, 0x8b, 0xec, 0x8b, 0x46, 0x08, 0x8b, 0x56, 0x0a,
        0x8b, 0x5e, 0x06, 0x03, 0xdb, 0x03, 0xdb, 0x89, 0x87,
        0x64, 0x42, 0x89, 0x97, 0x66, 0x42, 0x5d, 0xcb
    };
    static const uint8_t verified_get_far_idx_body[] = {
        0x55, 0x8b, 0xec, 0x56, 0x8a, 0x5e, 0x06, 0x2a, 0xff,
        0x03, 0xdb, 0x03, 0xdb, 0xc4, 0x36, 0xba, 0x67, 0x26,
        0x8b, 0x00, 0x26, 0x8b, 0x50, 0x02, 0x5e, 0x8b, 0xe5,
        0x5d, 0xcb
    };
    static const uint8_t verified_exe_37625_body[] = {
        0xc7, 0x06, 0xa0, 0x4e, 0x00, 0x00, 0xcb
    };
    static const uint8_t verified_exe_99679_body[] = {
        0x55, 0x8b, 0xec, 0xa0, 0x28, 0x4f, 0x25, 0x01, 0x00,
        0x3b, 0x46, 0x06, 0x75, 0x0a, 0x8b, 0x1e, 0x28, 0x4f,
        0xfe, 0x87, 0x2a, 0x4f, 0xeb, 0x14, 0x83, 0x3e, 0x28,
        0x4f, 0x0f, 0x73, 0x0d, 0xff, 0x06, 0x28, 0x4f, 0x8b,
        0x1e, 0x28, 0x4f, 0xc6, 0x87, 0x2a, 0x4f, 0x01, 0x8b,
        0xe5, 0x5d, 0xcb
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

    for (size_t i = 0; i < sizeof(verified_exe_94712_body); i++) {
        uint32_t address = (uint32_t)machine->img.load_seg * 16u +
                           EXE_94712_EXE_OFFSET + (uint32_t)i;
        if (mem_r8(address) != verified_exe_94712_body[i]) return false;
    }

    for (size_t i = 0; i < sizeof(verified_if0_helper_inc_fast_prefix); i++) {
        uint32_t address = (uint32_t)machine->img.load_seg * 16u +
                           IF0_HELPER_INC_EXE_OFFSET + (uint32_t)i;
        if (mem_r8(address) != verified_if0_helper_inc_fast_prefix[i]) return false;
    }
    /* The skipped slow branch contains a relocated far-call segment word. */
    if (mem_r8((uint32_t)machine->img.load_seg * 16u +
               IF0_HELPER_INC_EXE_OFFSET + 16u) != 0xcb) return false;

    for (size_t i = 0; i < sizeof(verified_exe_14360_body); i++) {
        uint32_t address = (uint32_t)machine->img.load_seg * 16u +
                           EXE_14360_EXE_OFFSET + (uint32_t)i;
        if (mem_r8(address) != verified_exe_14360_body[i]) return false;
    }
    for (size_t i = 0; i < sizeof(verified_set_far_arr_body); i++) {
        uint32_t address = (uint32_t)machine->img.load_seg * 16u +
                           SET_FAR_ARR_EXE_OFFSET + (uint32_t)i;
        if (mem_r8(address) != verified_set_far_arr_body[i]) return false;
    }
    for (size_t i = 0; i < sizeof(verified_get_far_idx_body); i++) {
        uint32_t address = (uint32_t)machine->img.load_seg * 16u +
                           GET_FAR_IDX_EXE_OFFSET + (uint32_t)i;
        if (mem_r8(address) != verified_get_far_idx_body[i]) return false;
    }
    for (size_t i = 0; i < sizeof(verified_exe_37625_body); i++) {
        uint32_t a = (uint32_t)machine->img.load_seg * 16u +
                     EXE_37625_A_OFFSET + (uint32_t)i;
        uint32_t b = (uint32_t)machine->img.load_seg * 16u +
                     EXE_37625_B_OFFSET + (uint32_t)i;
        if (mem_r8(a) != verified_exe_37625_body[i] ||
            mem_r8(b) != verified_exe_37625_body[i]) return false;
    }
    for (size_t i = 0; i < sizeof(verified_exe_99679_body); i++) {
        uint32_t address = (uint32_t)machine->img.load_seg * 16u +
                           EXE_99679_EXE_OFFSET + (uint32_t)i;
        if (mem_r8(address) != verified_exe_99679_body[i]) return false;
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
    if (!cpu86_hook_install(segment, offset, native_set_far_ptr, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + EXE_94712_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_94712_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_94712, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + IF0_HELPER_INC_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_if0_helper_inc_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_if0_helper_inc_nonzero, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + EXE_14360_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_14360_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_14360, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + SET_FAR_ARR_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_set_far_arr_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_set_far_arr, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + GET_FAR_IDX_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_get_far_idx_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_get_far_idx, NULL)) return false;

    g_exe_37625_hits = 0;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_37625_A_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    if (!cpu86_hook_install(segment, offset, native_exe_37625, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_37625_B_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    if (!cpu86_hook_install(segment, offset, native_exe_37625, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + EXE_99679_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_99679_hits = 0;
    return cpu86_hook_install(segment, offset, native_exe_99679, NULL);
}

uint64_t xanth_native_set_int_and_zero_hits(void) {
    return g_set_int_and_zero_hits;
}

uint64_t xanth_native_set_far_ptr_hits(void) {
    return g_set_far_ptr_hits;
}

uint64_t xanth_native_exe_94712_hits(void) {
    return g_exe_94712_hits;
}

uint64_t xanth_native_if0_helper_inc_hits(void) {
    return g_if0_helper_inc_hits;
}

uint64_t xanth_native_exe_14360_hits(void) {
    return g_exe_14360_hits;
}

uint64_t xanth_native_set_far_arr_hits(void) {
    return g_set_far_arr_hits;
}

uint64_t xanth_native_get_far_idx_hits(void) {
    return g_get_far_idx_hits;
}

uint64_t xanth_native_exe_37625_hits(void) {
    return g_exe_37625_hits;
}

uint64_t xanth_native_exe_99679_hits(void) {
    return g_exe_99679_hits;
}
