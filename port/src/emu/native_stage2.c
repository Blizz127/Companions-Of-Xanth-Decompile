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
#include "asset_check.h"
#include <string.h>

#include <stdint.h>

#define far
#define unsigned uint16_t
#define g0 xanth_add_mod_g0
#define g1 xanth_add_mod_g1
#include "../../../src/add_mod.c"
#undef g1
#undef g0
#undef unsigned
#undef far

#define far
#include "../../../src/set_int_and_zero.c"
#undef far
#define far
#include "../../../src/set_far_ptr.c"
#undef far
#define far
#include "../../../src/exe_136552.c"
#undef far
#define far
#define g exe_52710_global
#include "../../../src/exe_52710.c"
#undef g
#undef far
#define far
#include "../../../src/exe_112795.c"
#undef far
#define far
#define g0 exe_52674_g0
#define g1 exe_52674_g1
#include "../../../src/exe_52674.c"
#undef g1
#undef g0
#undef far
#define far
#include "../../../src/exe_112711.c"
#undef far
#define far
#define dst0 xanth_exe_103744_dst0
#define dst1 xanth_exe_103744_dst1
#define src0 xanth_exe_103744_src0
#define src1 xanth_exe_103744_src1
#include "../../../src/exe_103744.c"
#undef src1
#undef src0
#undef dst1
#undef dst0
#undef far

/* Host scratch backing for the source C body invoked by its guest adapter. */
unsigned g_idx;
int g_cnt[1];
char *g_tbl[1];

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

typedef struct {
    uint32_t exe_offset;
    uint16_t global_ds_offset;
} word_clear_unit;

static const word_clear_unit g_exe_37625_units[] = {
    {37625u, 0x0064u}, {52680u, 0x0102u}, {52713u, 0x0106u},
    {EXE_37625_A_OFFSET, EXE_37625_GLOBAL_DS_OFFSET},
    {EXE_37625_B_OFFSET, EXE_37625_GLOBAL_DS_OFFSET}
};
#define EXE_99679_EXE_OFFSET         99679u
#define EXE_99679_COUNTER_DS_OFFSET  0x4f28u
#define EXE_99679_TABLE_DS_OFFSET    0x4f2au
#define EXE_86810_EXE_OFFSET         86810u
#define EXE_86810_GLOBAL_DS_OFFSET   0x42e0u
#define EXE_84866_EXE_OFFSET         84866u
#define EXE_84866_GLOBAL_DS_OFFSET   0x6340u
#define SET_INT_PAIR_A_EXE_OFFSET   85189u
#define SET_INT_PAIR_A_G0_DS_OFFSET 0x6344u
#define SET_INT_PAIR_A_G1_DS_OFFSET 0x6dfeu
#define SET_INT_PAIR_B_EXE_OFFSET   103757u
#define SET_INT_PAIR_B_G0_DS_OFFSET 0x4f46u
#define SET_INT_PAIR_B_G1_DS_OFFSET 0x4f48u
#define SET_INT_A_EXE_OFFSET        85206u
#define SET_INT_A_GLOBAL_DS_OFFSET  0x6346u
#define SET_INT_B_EXE_OFFSET        112665u
#define SET_INT_B_GLOBAL_DS_OFFSET  0x67c0u
#define CLEAR_BYTE_EXE_OFFSET       106736u
#define SWAP_INT_EXE_OFFSET         108184u
#define SWAP_INT_GLOBAL_DS_OFFSET   0x6e52u
#define EXE_115346_OFFSET           115346u
#define EXE_115346_INDEX_DS_OFFSET  0x51e0u
#define EXE_115346_ARRAY_DS_OFFSET  0x68c0u
#define ARR_SET_ONE_OFFSET          115161u
#define ARR_SET_ONE_INDEX_DS_OFFSET 0x51e0u
#define ARR_SET_ONE_ARRAY_DS_OFFSET 0x68d0u
#define EXE_114942_OFFSET            114942u
#define STORE_TWO_GLOBALS_OFFSET     85166u
#define SET_INT_IF_GE0_OFFSET        90625u
#define IABS_OFFSET                  17806u
#define SET_FAR_ARR_CHK_OFFSET       94589u
#define ADD_MOD_EXE_OFFSET          56247u
#define ADD_MOD_G0_DS_OFFSET        0x025eu
#define ADD_MOD_G1_DS_OFFSET        0x0260u
#define SET_FIELDS_EXE_OFFSET       105702u
#define EXE_112853_OFFSET           112853u
#define EXE_100016_OFFSET           100016u
#define EXE_100016_GLOBAL_A_DS      0x6428u
#define EXE_100016_GLOBAL_B_DS      0x642au
#define EXE_100016_FLAGS_DS         0x4e9eu
#define EXE_103774_OFFSET           103774u
#define EXE_103774_GLOBAL_A_DS      0x4f46u
#define EXE_103774_GLOBAL_B_DS      0x4f48u
#define EXE_100203_OFFSET           100203u
#define EXE_103744_OFFSET           103744u
#define EXE_103744_DST0_DS_OFFSET   0x4f46u
#define EXE_103744_DST1_DS_OFFSET   0x4f48u
#define EXE_103744_SRC0_DS_OFFSET   0x4f4au
#define EXE_103744_SRC1_DS_OFFSET   0x4f4cu
#define EXE_136552_OFFSET            136552u
#define EXE_52710_OFFSET              52710u
#define EXE_52710_GLOBAL_DS_OFFSET    0x0106u
#define EXE_112795_OFFSET            112795u
#define EXE_112795_INDEX_DS_OFFSET   0x67c0u
#define EXE_112795_COUNT_DS_OFFSET   0x67e2u
#define EXE_112795_TABLE_DS_OFFSET   0x67c2u
#define EXE_52674_OFFSET              52674u
#define EXE_52674_G0_DS_OFFSET        0x0106u
#define EXE_52674_G1_DS_OFFSET        0x0102u
#define EXE_112711_OFFSET            112711u
#define EXE_34775_OFFSET              34775u
#define EXE_34775_DATA_SEGMENT        0x38afu
#define EXE_34775_DATA_OFFSET         0x52b2u

typedef struct {
    uint16_t exe_offset;
    uint16_t global_ds_offset;
} byte_one_unit;

static const byte_one_unit g_set_byte_one_units[] = {
    {28365u, 0x525bu}, {29169u, 0x525au}, {30199u, 0x525cu},
    {31178u, 0x5301u}, {32631u, 0x52ffu}, {35386u, 0x52feu}
};

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
static uint64_t g_exe_86810_hits;
static uint64_t g_exe_84866_hits;
static uint64_t g_set_int_pair_a_hits;
static uint64_t g_set_int_pair_b_hits;
static uint64_t g_set_int_a_hits;
static uint64_t g_set_int_b_hits;
static uint64_t g_clear_byte_hits;
static uint64_t g_swap_int_hits;
static uint64_t g_exe_115346_hits;
static uint64_t g_arr_set_one_hits;
static uint64_t g_exe_114942_hits;
static uint64_t g_exe_114942_negative_hits;
static uint64_t g_store_two_globals_hits;
static uint64_t g_set_int_if_ge0_hits;
static uint64_t g_iabs_hits;
static uint64_t g_set_far_arr_chk_hits;
static uint64_t g_set_byte_one_hits;
static uint64_t g_exe_136552_hits;
static uint64_t g_exe_52710_hits;
static uint64_t g_exe_112795_hits;
static uint64_t g_exe_52674_hits;
static uint64_t g_exe_112711_hits;
static uint64_t g_exe_34775_hits;
static uint64_t g_add_mod_hits;
static uint64_t g_set_fields_hits;
static uint64_t g_exe_112853_hits;
static uint64_t g_exe_100016_fast_hits;
static uint64_t g_exe_100016_store_hits;
static uint64_t g_exe_103774_negative_hits;
static uint64_t g_exe_100203_prefix_hits;
static uint64_t g_exe_103744_hits;
static uint32_t g_exe_112711_record_scratch[82];
static uint8_t g_exe_112795_record_scratch[65536];
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
    const word_clear_unit *unit = (const word_clear_unit *)user;
    vm *machine = (vm *)cpu->vm;
    if (!unit || cpu->step_budget_remaining < 2u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 8u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 8u)))
            return HOOK_CONTINUE;
    }

    seg_w16(cpu->s[CPU_DS], unit->global_ds_offset, 0);
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

/* Both recovered getters are straight DS loads followed by a far return. */
static hook_result_t native_exe_86810(cpu86 *cpu, void *user) {
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

    cpu->r[CPU_AX] = seg_r16(cpu->s[CPU_DS], EXE_86810_GLOBAL_DS_OFFSET);
    cpu->cycles += 2u * 4u;
    cpu->step_guest_insns = 2;
    g_exe_86810_hits++;
    return HOOK_DID_RETF;
}

static hook_result_t native_exe_84866(cpu86 *cpu, void *user) {
    vm *machine = (vm *)cpu->vm;
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

    cpu->r[CPU_AX] = seg_r16(cpu->s[CPU_DS], EXE_84866_GLOBAL_DS_OFFSET);
    cpu->r[CPU_DX] = seg_r16(cpu->s[CPU_DS],
                             (uint16_t)(EXE_84866_GLOBAL_DS_OFFSET + 2u));
    cpu->cycles += 3u * 4u;
    cpu->step_guest_insns = 3;
    g_exe_84866_hits++;
    return HOOK_DID_RETF;
}

/* Two recovered set_int_pair bodies store their words into guest DS globals. */
static hook_result_t native_set_int_pair(cpu86 *cpu, void *user) {
    const bool second_copy = (uintptr_t)user != 0;
    const uint16_t g0 = second_copy ? SET_INT_PAIR_B_G0_DS_OFFSET
                                    : SET_INT_PAIR_A_G0_DS_OFFSET;
    const uint16_t g1 = second_copy ? SET_INT_PAIR_B_G1_DS_OFFSET
                                    : SET_INT_PAIR_A_G1_DS_OFFSET;
    vm *machine = (vm *)cpu->vm;
    if (cpu->step_budget_remaining < 8u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 32u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 32u)))
            return HOOK_CONTINUE;
    }

    seg_w16(cpu->s[CPU_DS], g0,
            seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4)));
    cpu->r[CPU_AX] = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 6));
    seg_w16(cpu->s[CPU_DS], g1, cpu->r[CPU_AX]);
    cpu->cycles += 8u * 4u;
    cpu->step_guest_insns = 8;
    if (second_copy) g_set_int_pair_b_hits++;
    else g_set_int_pair_a_hits++;
    return HOOK_DID_RETF;
}

static hook_result_t native_set_int(cpu86 *cpu, void *user) {
    const bool second_copy = (uintptr_t)user != 0;
    const uint16_t global = second_copy ? SET_INT_B_GLOBAL_DS_OFFSET
                                        : SET_INT_A_GLOBAL_DS_OFFSET;
    vm *machine = (vm *)cpu->vm;
    if (cpu->step_budget_remaining < 6u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 24u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 24u)))
            return HOOK_CONTINUE;
    }

    cpu->r[CPU_AX] = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4));
    seg_w16(cpu->s[CPU_DS], global, cpu->r[CPU_AX]);
    cpu->cycles += 6u * 4u;
    cpu->step_guest_insns = 6;
    if (second_copy) g_set_int_b_hits++;
    else g_set_int_a_hits++;
    return HOOK_DID_RETF;
}

/* Lower recovered clear_byte(char far *p), with the store targeting guest memory. */
static hook_result_t native_clear_byte(cpu86 *cpu, void *user) {
    uint16_t pointer_offset = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4));
    uint16_t pointer_segment = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 6));
    vm *machine = (vm *)cpu->vm;
    if (cpu->step_budget_remaining < 6u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 24u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 24u)))
            return HOOK_CONTINUE;
    }

    cpu->r[CPU_BX] = pointer_offset;
    cpu->s[CPU_ES] = pointer_segment;
    seg_w8(pointer_segment, pointer_offset, 0);
    cpu->cycles += 6u * 4u;
    cpu->step_guest_insns = 6;
    g_clear_byte_hits++;
    return HOOK_DID_RETF;
}

/* Lower recovered swap_int(int): preserve SUB SP,2 flags and guest DS state. */
static hook_result_t native_swap_int(cpu86 *cpu, void *user) {
    uint16_t arg = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4));
    uint16_t old = seg_r16(cpu->s[CPU_DS], SWAP_INT_GLOBAL_DS_OFFSET);
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

    /* The stack allocation is later discarded by MOV SP,BP; only its flags remain. */
    (void)alu_op(cpu, ALU_SUB, cpu->r[CPU_SP], 2u, 16);
    seg_w16(cpu->s[CPU_DS], SWAP_INT_GLOBAL_DS_OFFSET, arg);
    cpu->r[CPU_AX] = old;
    cpu->cycles += 11u * 4u;
    cpu->step_guest_insns = 11;
    g_swap_int_hits++;
    return HOOK_DID_RETF;
}

/* Lower exe_115346: arr[idx] = -1; preserve the ADD BX,BX result flags. */
static hook_result_t native_exe_115346(cpu86 *cpu, void *user) {
    vm *machine = (vm *)cpu->vm;
    uint16_t index = seg_r16(cpu->s[CPU_DS], EXE_115346_INDEX_DS_OFFSET);
    uint16_t bx = (uint16_t)(index * 2u);
    if (cpu->step_budget_remaining < 4u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 16u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 16u)))
            return HOOK_CONTINUE;
    }

    cpu->r[CPU_BX] = index;
    cpu->r[CPU_BX] = alu_op(cpu, ALU_ADD, cpu->r[CPU_BX], cpu->r[CPU_BX], 16);
    bx = cpu->r[CPU_BX];
    seg_w16(cpu->s[CPU_DS], (uint16_t)(EXE_115346_ARRAY_DS_OFFSET + bx), 0xffffu);
    cpu->cycles += 4u * 4u;
    cpu->step_guest_insns = 4;
    g_exe_115346_hits++;
    return HOOK_DID_RETF;
}

/* Lower arr_set_one's nonzero branch; the zero branch remains interpreted. */
static hook_result_t native_arr_set_one(cpu86 *cpu, void *user) {
    uint16_t arg = seg_r16(cpu->s[CPU_SS], (uint16_t)(cpu->r[CPU_SP] + 4));
    vm *machine = (vm *)cpu->vm;
    if (arg == 0 || cpu->step_budget_remaining < 9u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= 36u ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= 36u)))
            return HOOK_CONTINUE;
    }

    cpu->r[CPU_BX] = seg_r16(cpu->s[CPU_DS], ARR_SET_ONE_INDEX_DS_OFFSET);
    cpu->r[CPU_BX] = alu_op(cpu, ALU_ADD, cpu->r[CPU_BX], cpu->r[CPU_BX], 16);
    seg_w16(cpu->s[CPU_DS],
            (uint16_t)(ARR_SET_ONE_ARRAY_DS_OFFSET + cpu->r[CPU_BX]), 1u);
    cpu->cycles += 9u * 4u;
    cpu->step_guest_insns = 9;
    g_arr_set_one_hits++;
    return HOOK_DID_RETF;
}

/* Lower exe_114942's signed-negative clear and nonnegative table paths. */
static hook_result_t native_exe_114942(cpu86 *cpu, void *user) {
    uint16_t entry_sp = cpu->r[CPU_SP];
    uint16_t saved_bp = cpu->r[CPU_BP];
    uint16_t saved_si = cpu->r[CPU_SI];
    uint16_t index = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 4u));
    uint16_t out_a = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 6u));
    uint16_t seg_a = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 8u));
    uint16_t out_b = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 10u));
    uint16_t seg_b = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 12u));
    vm *machine = (vm *)cpu->vm;
    uint16_t bx, value;
    const bool negative = (int16_t)index < 0;
    const uint8_t guest_insns = negative ? 15u : 17u;
    const uint32_t cycles = (uint32_t)guest_insns * 4u;

    if (cpu->step_budget_remaining < guest_insns)
        return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= cycles)))
            return HOOK_CONTINUE;
    }

    if (negative) {
        (void)alu_op(cpu, ALU_SUB, index, 0u, 16);
        cpu->r[CPU_AX] = alu_op(cpu, ALU_XOR, 0u, 0u, 16);
        cpu->r[CPU_BX] = out_a;
        cpu->s[CPU_ES] = seg_a;
        seg_w16(seg_a, out_a, cpu->r[CPU_AX]);
        cpu->r[CPU_BX] = out_b;
        cpu->s[CPU_ES] = seg_b;
        seg_w16(seg_b, out_b, cpu->r[CPU_AX]);
    } else {
        bx = index;
        bx = alu_op(cpu, ALU_ADD, bx, bx, 16);
        value = seg_r16(cpu->s[CPU_DS], (uint16_t)(bx + 0x6840u));
        cpu->r[CPU_SI] = saved_si;
        cpu->s[CPU_ES] = seg_a;
        seg_w16(seg_a, out_a, value);
        cpu->r[CPU_AX] = seg_r16(cpu->s[CPU_DS], (uint16_t)(bx + 0x6850u));
        cpu->r[CPU_BX] = out_b;
        cpu->s[CPU_ES] = seg_b;
        seg_w16(seg_b, out_b, cpu->r[CPU_AX]);
    }
    cpu->r[CPU_BP] = saved_bp;
    cpu->r[CPU_SP] = entry_sp;
    cpu->cycles += cycles;
    cpu->step_guest_insns = guest_insns;
    g_exe_114942_hits++;
    if (negative) g_exe_114942_negative_hits++;
    return HOOK_DID_RETF;
}

#ifdef XANTH_NATIVE_STAGE2_TESTING
hook_result_t xanth_native_stage2_test_exe_114942(cpu86 *cpu) {
    return native_exe_114942(cpu, NULL);
}
#endif

/* Lower store_two_globals: copy two DS words to caller-provided far pointers. */
static hook_result_t native_store_two_globals(cpu86 *cpu, void *user) {
    uint16_t entry_sp = cpu->r[CPU_SP];
    uint16_t saved_bp = cpu->r[CPU_BP];
    uint16_t out_a = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 4u));
    uint16_t seg_a = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 6u));
    uint16_t out_b = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 8u));
    uint16_t seg_b = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 10u));
    uint16_t value_a = seg_r16(cpu->s[CPU_DS], 0x6344u);
    uint16_t value_b = seg_r16(cpu->s[CPU_DS], 0x6dfeu);
    vm *machine = (vm *)cpu->vm;
    const uint32_t cycles = 40u;
    if (cpu->step_budget_remaining < 10u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= cycles)))
            return HOOK_CONTINUE;
    }

    seg_w16(seg_a, out_a, value_a);
    cpu->s[CPU_ES] = seg_b;
    cpu->r[CPU_BX] = out_b;
    seg_w16(seg_b, out_b, value_b);
    cpu->r[CPU_AX] = value_b;
    cpu->r[CPU_BP] = saved_bp;
    cpu->r[CPU_SP] = entry_sp;
    cpu->cycles += cycles;
    cpu->step_guest_insns = 10;
    g_store_two_globals_hits++;
    return HOOK_DID_RETF;
}

/* Lower set_int_if_ge0, including its no-store negative path. */
static hook_result_t native_set_int_if_ge0(cpu86 *cpu, void *user) {
    uint16_t entry_sp = cpu->r[CPU_SP];
    uint16_t saved_bp = cpu->r[CPU_BP];
    uint16_t value = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 4u));
    uint32_t cycles = (int16_t)value < 0 ? 24u : 32u;
    vm *machine = (vm *)cpu->vm;
    if (cpu->step_budget_remaining < cycles / 4u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= cycles)))
            return HOOK_CONTINUE;
    }

    (void)alu_op(cpu, ALU_CMP, value, 0, 16);
    if ((int16_t)value >= 0) {
        cpu->r[CPU_AX] = value;
        seg_w16(cpu->s[CPU_DS], 0x4d36u, value);
    }
    cpu->r[CPU_BP] = saved_bp;
    cpu->r[CPU_SP] = entry_sp;
    cpu->cycles += cycles;
    cpu->step_guest_insns = (uint8_t)(cycles / 4u);
    g_set_int_if_ge0_hits++;
    return HOOK_DID_RETF;
}

/* Lower iabs with the guest CWD/XOR/SUB sequence and its exact final flags. */
static hook_result_t native_iabs(cpu86 *cpu, void *user) {
    uint16_t entry_sp = cpu->r[CPU_SP];
    uint16_t saved_bp = cpu->r[CPU_BP];
    uint16_t value = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 4u));
    uint16_t sign = ((int16_t)value < 0) ? 0xffffu : 0;
    vm *machine = (vm *)cpu->vm;
    const uint32_t cycles = 32u;
    if (cpu->step_budget_remaining < 8u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= cycles)))
            return HOOK_CONTINUE;
    }

    cpu->r[CPU_DX] = sign;
    value = alu_op(cpu, ALU_XOR, value, sign, 16);
    value = alu_op(cpu, ALU_SUB, value, sign, 16);
    cpu->r[CPU_AX] = value;
    cpu->r[CPU_BP] = saved_bp;
    cpu->r[CPU_SP] = entry_sp;
    cpu->cycles += cycles;
    cpu->step_guest_insns = 8;
    g_iabs_hits++;
    return HOOK_DID_RETF;
}

/* Lower the full bounds-checked guest far-pointer array store. */
static hook_result_t native_set_far_arr_chk(cpu86 *cpu, void *user) {
    uint16_t entry_sp = cpu->r[CPU_SP];
    uint16_t saved_bp = cpu->r[CPU_BP];
    uint16_t index = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 4u));
    uint16_t ptr_off = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 6u));
    uint16_t ptr_seg = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 8u));
    uint16_t count = seg_r16(cpu->s[CPU_DS], 0x4db4u);
    bool negative = (int16_t)index < 0;
    bool out_of_range = !negative && (int16_t)index >= (int16_t)count;
    uint8_t guest_insns = negative ? 6u : (out_of_range ? 9u : 16u);
    uint32_t cycles = (uint32_t)guest_insns * 4u;
    vm *machine = (vm *)cpu->vm;
    if (cpu->step_budget_remaining < guest_insns) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= cycles)))
            return HOOK_CONTINUE;
    }

    (void)alu_op(cpu, ALU_CMP, index, 0, 16);
    if (!negative) {
        cpu->r[CPU_AX] = count;
        (void)alu_op(cpu, ALU_CMP, index, count, 16);
        if (!out_of_range) {
            uint16_t bx = alu_op(cpu, ALU_ADD, index, index, 16);
            bx = alu_op(cpu, ALU_ADD, bx, bx, 16);
            cpu->r[CPU_BX] = bx;
            cpu->r[CPU_AX] = ptr_off;
            cpu->r[CPU_DX] = ptr_seg;
            seg_w16(cpu->s[CPU_DS], (uint16_t)(0x63e8u + bx), ptr_off);
            seg_w16(cpu->s[CPU_DS], (uint16_t)(0x63eau + bx), ptr_seg);
        }
    }
    cpu->r[CPU_BP] = saved_bp;
    cpu->r[CPU_SP] = entry_sp;
    cpu->cycles += cycles;
    cpu->step_guest_insns = guest_insns;
    g_set_far_arr_chk_hits++;
    return HOOK_DID_RETF;
}

/* One recovered set_byte_one body is installed at each distinct C-unit address. */
static hook_result_t native_set_byte_one(cpu86 *cpu, void *user) {
    const byte_one_unit *unit = (const byte_one_unit *)user;
    vm *machine = (vm *)cpu->vm;
    const uint32_t cycles = 8u;
    if (!unit || cpu->step_budget_remaining < 2u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= cycles)))
            return HOOK_CONTINUE;
    }

    seg_w8(cpu->s[CPU_DS], unit->global_ds_offset, 1u);
    cpu->cycles += cycles;
    cpu->step_guest_insns = 2;
    g_set_byte_one_hits++;
    return HOOK_DID_RETF;
}

/* The recovered C unit returns -1; retail is exactly MOV AX,FFFF / RETF. */
static hook_result_t native_exe_136552(cpu86 *cpu, void *user) {
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

    cpu->r[CPU_AX] = (uint16_t)exe_136552();
    cpu->cycles += 8u;
    cpu->step_guest_insns = 2;
    g_exe_136552_hits++;
    return HOOK_DID_RETF;
}

/* Recovered take-and-clear of DS:0106; retail is MOV/STORE-0/RETF. */
static hook_result_t native_exe_52710(cpu86 *cpu, void *user) {
    vm *machine = (vm *)cpu->vm;
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

    exe_52710_global = (int16_t)seg_r16(cpu->s[CPU_DS], EXE_52710_GLOBAL_DS_OFFSET);
    cpu->r[CPU_AX] = (uint16_t)exe_52710();
    seg_w16(cpu->s[CPU_DS], EXE_52710_GLOBAL_DS_OFFSET, 0);
    cpu->cycles += 12u;
    cpu->step_guest_insns = 3;
    g_exe_52710_hits++;
    return HOOK_DID_RETF;
}

/* Lower the recovered bounded bit-set, calling its C body on a scratch record. */
static hook_result_t native_exe_112795(cpu86 *cpu, void *user) {
    uint16_t entry_sp = cpu->r[CPU_SP];
    uint16_t saved_bp = cpu->r[CPU_BP];
    uint16_t index = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 4u));
    uint16_t table_index = seg_r16(cpu->s[CPU_DS], EXE_112795_INDEX_DS_OFFSET);
    uint16_t count_index = (uint16_t)(table_index * 2u);
    uint16_t count = seg_r16(cpu->s[CPU_DS],
                             (uint16_t)(EXE_112795_COUNT_DS_OFFSET + count_index));
    bool out_of_range = (int16_t)count <= (int16_t)index;
    uint8_t guest_insns;
    uint32_t cycles;
    vm *machine = (vm *)cpu->vm;

    /* Negative indexes or very large records use the interpreter's far-pointer rules. */
    if ((int16_t)index < 0 || index > 3276u) return HOOK_CONTINUE;

    guest_insns = out_of_range ? 11u : 22u;
    cycles = (uint32_t)guest_insns * 4u;
    if (cpu->step_budget_remaining < guest_insns) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= cycles)))
            return HOOK_CONTINUE;
    }

    cpu->r[CPU_AX] = index;
    cpu->r[CPU_BX] = alu_op(cpu, ALU_ADD, table_index, table_index, 16);
    (void)alu_op(cpu, ALU_CMP, count, index, 16);

    if (!out_of_range) {
            uint16_t record_offset = (uint16_t)(index * 20u);
            uint16_t pointer_index = (uint16_t)(table_index * 4u);
            uint16_t pointer_offset = seg_r16(cpu->s[CPU_DS],
                (uint16_t)(EXE_112795_TABLE_DS_OFFSET + pointer_index));
            uint16_t pointer_segment = seg_r16(cpu->s[CPU_DS],
                (uint16_t)(EXE_112795_TABLE_DS_OFFSET + pointer_index + 2u));
            uint16_t target = (uint16_t)(pointer_offset + record_offset + 1u);
            uint8_t prior = seg_r8(pointer_segment, target);

            g_idx = 0;
            g_cnt[0] = (int16_t)count;
            g_tbl[0] = (char *)g_exe_112795_record_scratch;
            g_exe_112795_record_scratch[record_offset + 1u] = prior;
            exe_112795((int16_t)index);

            cpu->r[CPU_AX] = 20u;
            alu_imul16(cpu, index);
            cpu->r[CPU_BX] = table_index;
            cpu->r[CPU_BX] = alu_op(cpu, ALU_ADD,
                                    cpu->r[CPU_BX], cpu->r[CPU_BX], 16);
            cpu->r[CPU_BX] = alu_op(cpu, ALU_ADD,
                                    cpu->r[CPU_BX], cpu->r[CPU_BX], 16);
            cpu->r[CPU_CX] = seg_r16(cpu->s[CPU_DS],
                (uint16_t)(EXE_112795_TABLE_DS_OFFSET + cpu->r[CPU_BX]));
            cpu->r[CPU_DX] = seg_r16(cpu->s[CPU_DS],
                (uint16_t)(EXE_112795_TABLE_DS_OFFSET + cpu->r[CPU_BX] + 2u));
            cpu->r[CPU_CX] = alu_op(cpu, ALU_ADD, cpu->r[CPU_CX],
                                    cpu->r[CPU_AX], 16);
            cpu->r[CPU_BX] = cpu->r[CPU_CX];
            cpu->s[CPU_ES] = cpu->r[CPU_DX];
            target = (uint16_t)(cpu->r[CPU_BX] + 1u);
            prior = seg_r8(cpu->s[CPU_ES], target);
            (void)alu_op(cpu, ALU_OR, prior, 0x80u, 8);
            seg_w8(cpu->s[CPU_ES], target,
                   g_exe_112795_record_scratch[record_offset + 1u]);
    }

    cpu->r[CPU_BP] = saved_bp;
    cpu->r[CPU_SP] = entry_sp;
    cpu->cycles += cycles;
    cpu->step_guest_insns = guest_insns;
    g_exe_112795_hits++;
    return HOOK_DID_RETF;
}

/* Recovered startup initializer: set DS:0106 to one and DS:0102 to zero. */
static hook_result_t native_exe_52674(cpu86 *cpu, void *user) {
    vm *machine = (vm *)cpu->vm;
    const uint32_t cycles = 12u;
    if (cpu->step_budget_remaining < 3u) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= cycles)))
            return HOOK_CONTINUE;
    }

    exe_52674();
    seg_w16(cpu->s[CPU_DS], EXE_52674_G0_DS_OFFSET,
            (uint16_t)exe_52674_g0);
    seg_w16(cpu->s[CPU_DS], EXE_52674_G1_DS_OFFSET,
            (uint16_t)exe_52674_g1);
    cpu->cycles += cycles;
    cpu->step_guest_insns = 3;
    g_exe_52674_hits++;
    return HOOK_DID_RETF;
}

/* Run the recovered record walk on a host scratch table, then copy bit writes back. */
static hook_result_t native_exe_112711(cpu86 *cpu, void *user) {
    uint16_t entry_sp = cpu->r[CPU_SP];
    uint16_t saved_bp = cpu->r[CPU_BP];
    uint16_t value = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 4u));
    uint16_t table_index = seg_r16(cpu->s[CPU_DS], EXE_112795_INDEX_DS_OFFSET);
    uint16_t count_index = (uint16_t)(table_index * 2u);
    uint16_t count = seg_r16(cpu->s[CPU_DS],
                             (uint16_t)(EXE_112795_COUNT_DS_OFFSET + count_index));
    bool has_records = (int16_t)count > 0;
    uint16_t pointer_offset = 0, pointer_segment = 0;
    uint8_t guest_insns = 11u;
    uint32_t cycles = 44u;
    size_t matches = 0;
    uint8_t *scratch = (uint8_t *)g_exe_112711_record_scratch;
    vm *machine = (vm *)cpu->vm;

    /* Large tables use the interpreter so both event boundaries and local widths stay exact. */
    if (has_records && count > 16u) return HOOK_CONTINUE;
    if (has_records) {
        uint16_t pointer_index = (uint16_t)(table_index * 4u);
        pointer_offset = seg_r16(cpu->s[CPU_DS],
            (uint16_t)(EXE_112795_TABLE_DS_OFFSET + pointer_index));
        pointer_segment = seg_r16(cpu->s[CPU_DS],
            (uint16_t)(EXE_112795_TABLE_DS_OFFSET + pointer_index + 2u));
        for (uint16_t i = 0; i < count; i++) {
            uint16_t record_offset = (uint16_t)(i * 20u);
            uint8_t *record = scratch + 2u + record_offset;
            for (uint16_t b = 0; b < 20u; b++)
                record[b] = seg_r8(pointer_segment,
                    (uint16_t)(pointer_offset + record_offset + b));
            {
                uint16_t word = (uint16_t)(record[10] | ((uint16_t)record[11] << 8));
                record[12] = ((int16_t)word < 0) ? 0xffu : 0u;
                record[13] = record[12];
                if ((int16_t)word == (int16_t)value) matches++;
            }
        }
        {
            uint32_t instruction_count = 12u + (uint32_t)count * 15u +
                                         (uint32_t)matches;
            if (instruction_count > UINT8_MAX) return HOOK_CONTINUE;
            guest_insns = (uint8_t)instruction_count;
            cycles = instruction_count * 4u;
        }
    }

    if (cpu->step_budget_remaining < guest_insns) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= cycles)))
            return HOOK_CONTINUE;
    }

    if (has_records) {
        g_idx = 0;
        g_cnt[0] = (int16_t)count;
        g_tbl[0] = (char *)(scratch + 2u);
        exe_112711((int16_t)value);
        for (uint16_t i = 0; i < count; i++) {
            uint16_t target = (uint16_t)(pointer_offset + i * 20u + 1u);
            seg_w8(pointer_segment, target, scratch[2u + i * 20u + 1u]);
        }
        cpu->r[CPU_AX] = count;
        cpu->r[CPU_BX] = alu_op(cpu, ALU_ADD, table_index, table_index, 16);
        cpu->s[CPU_ES] = pointer_segment;
        (void)alu_op(cpu, ALU_CMP, count, count, 16);
    } else {
        cpu->r[CPU_BX] = alu_op(cpu, ALU_ADD, table_index, table_index, 16);
        (void)alu_op(cpu, ALU_CMP, count, 0, 16);
    }

    cpu->r[CPU_BP] = saved_bp;
    cpu->r[CPU_SP] = entry_sp;
    cpu->cycles += cycles;
    cpu->step_guest_insns = guest_insns;
    g_exe_112711_hits++;
    return HOOK_DID_RETF;
}

/* Lower the byte-verified assembly data setter, retaining its far return cleanup. */
static hook_result_t native_exe_34775(cpu86 *cpu, void *user) {
    const uint16_t entry_sp = cpu->r[CPU_SP];
    const uint16_t arg = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 4u));
    const uint16_t return_ip = seg_r16(cpu->s[CPU_SS], entry_sp);
    const uint16_t return_cs = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 2u));
    const uint16_t old_bp = cpu->r[CPU_BP];
    vm *machine = (vm *)cpu->vm;
    const uint16_t instruction_count = 21u;
    const uint64_t cycles = (uint64_t)instruction_count * 4u;

    if (cpu->step_budget_remaining < instruction_count) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= cycles)))
            return HOOK_CONTINUE;
    }

    /* Recovered code writes DS=38AF:52B2 from arg and returns AX=0.
     * Its SUB SP,2 is the only flags-changing instruction; RETF 2 cleans
     * the argument after the two far-return words. */
    (void)alu_op(cpu, ALU_SUB, (uint16_t)(entry_sp - 2u), 2u, 16);
    seg_w16((uint16_t)(machine->img.load_seg + EXE_34775_DATA_SEGMENT),
            EXE_34775_DATA_OFFSET, arg);
    cpu->r[CPU_AX] = 0;
    cpu->r[CPU_BP] = old_bp;
    cpu->ip = return_ip;
    cpu->s[CPU_CS] = return_cs;
    cpu->r[CPU_SP] = (uint16_t)(entry_sp + 6u);
    cpu->cycles += cycles;
    cpu->step_guest_insns = (uint8_t)instruction_count;
    g_exe_34775_hits++;
    return HOOK_DID_SETIP;
}

/* Run recovered 16-bit C, then preserve the retail register/flag/ABI result. */
static hook_result_t native_add_mod(cpu86 *cpu, void *user) {
    const uint16_t entry_sp = cpu->r[CPU_SP];
    const uint16_t old_bp = cpu->r[CPU_BP];
    const uint16_t arg = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 4u));
    const uint16_t old_g0 = seg_r16(cpu->s[CPU_DS], ADD_MOD_G0_DS_OFFSET);
    const uint16_t old_g1 = seg_r16(cpu->s[CPU_DS], ADD_MOD_G1_DS_OFFSET);
    const uint16_t accumulated = (uint16_t)(old_g0 + arg);
    const uint16_t quotient = (uint16_t)(accumulated / 0x05a0u);
    const uint16_t remainder = (uint16_t)(accumulated % 0x05a0u);
    vm *machine = (vm *)cpu->vm;
    const uint16_t instruction_count = 15u;
    const uint64_t cycles = (uint64_t)instruction_count * 4u;

    if (cpu->step_budget_remaining < instruction_count) return HOOK_CONTINUE;
    if (machine) {
        uint64_t next_tick = machine->next_tick_cycles;
        uint64_t dma_end = machine->sb.dma_end_cycles;
        if (machine->cycles_per_second == 0 || next_tick <= cpu->cycles ||
            next_tick - cpu->cycles <= cycles ||
            (machine->sb.dma_active &&
             (dma_end <= cpu->cycles || dma_end - cpu->cycles <= cycles)))
            return HOOK_CONTINUE;
    }

    xanth_add_mod_g0 = old_g0;
    xanth_add_mod_g1 = old_g1;
    add_mod(arg);
    seg_w16(cpu->s[CPU_DS], ADD_MOD_G0_DS_OFFSET,
            (uint16_t)xanth_add_mod_g0);
    seg_w16(cpu->s[CPU_DS], ADD_MOD_G1_DS_OFFSET,
            (uint16_t)xanth_add_mod_g1);

    /* Final DIV leaves the preceding SUB DX,DX flag image in this 8086 core. */
    cpu->r[CPU_AX] = quotient;
    cpu->r[CPU_CX] = 0x05a0u;
    cpu->r[CPU_DX] = 0;
    (void)alu_op(cpu, ALU_SUB, 0, 0, 16);
    cpu->r[CPU_DX] = remainder;
    cpu->r[CPU_BP] = old_bp;
    cpu->r[CPU_SP] = entry_sp;
    cpu->cycles += cycles;
    cpu->step_guest_insns = (uint8_t)instruction_count;
    g_add_mod_hits++;
    return HOOK_DID_RETF;
}

/* Lower the exact src/set_fields.c far-pointer stores and visible ABI state. */
static hook_result_t native_set_fields(cpu86 *cpu, void *user) {
    const uint16_t entry_sp = cpu->r[CPU_SP];
    const uint16_t pointer_offset = seg_r16(cpu->s[CPU_SS],
                                             (uint16_t)(entry_sp + 4u));
    const uint16_t pointer_segment = seg_r16(cpu->s[CPU_SS],
                                              (uint16_t)(entry_sp + 6u));
    const uint16_t value_a = seg_r16(cpu->s[CPU_SS],
                                      (uint16_t)(entry_sp + 8u));
    const uint16_t value_b = seg_r16(cpu->s[CPU_SS],
                                      (uint16_t)(entry_sp + 10u));
    const uint16_t old_bp = cpu->r[CPU_BP];
    vm *machine = (vm *)cpu->vm;
    const uint16_t count = 9u;
    const uint64_t cycles = (uint64_t)count * 4u;
    (void)user;

    if (cpu->step_budget_remaining < count) return HOOK_CONTINUE;
    if (machine && (machine->cycles_per_second == 0 ||
        machine->next_tick_cycles <= cpu->cycles ||
        machine->next_tick_cycles - cpu->cycles <= cycles ||
        (machine->sb.dma_active && (machine->sb.dma_end_cycles <= cpu->cycles ||
         machine->sb.dma_end_cycles - cpu->cycles <= cycles))))
        return HOOK_CONTINUE;

    seg_w16(pointer_segment, (uint16_t)(pointer_offset + 2u), value_a);
    seg_w16(pointer_segment, (uint16_t)(pointer_offset + 4u), value_b);
    cpu->r[CPU_AX] = value_b;
    cpu->r[CPU_BX] = pointer_offset;
    cpu->r[CPU_BP] = old_bp;
    cpu->s[CPU_ES] = pointer_segment;
    cpu->cycles += cycles;
    cpu->step_guest_insns = (uint8_t)count;
    g_set_fields_hits++;
    return HOOK_DID_RETF;
}

/* Lower exe_112853: index a far table, select a record, return its +10 word. */
static hook_result_t native_exe_112853(cpu86 *cpu, void *user) {
    const uint16_t entry_sp = cpu->r[CPU_SP];
    const uint16_t index = seg_r16(cpu->s[CPU_SS],
                                    (uint16_t)(entry_sp + 4u));
    const uint16_t row = seg_r16(cpu->s[CPU_SS],
                                  (uint16_t)(entry_sp + 6u));
    const int32_t product = (int32_t)(int16_t)0x0014 * (int32_t)(int16_t)row;
    const uint16_t product_lo = (uint16_t)product;
    const uint16_t table_index = (uint16_t)(index * 4u);
    const uint16_t table_offset = (uint16_t)(table_index + 0x67c2u);
    const uint16_t record_offset = seg_r16(cpu->s[CPU_DS], table_offset);
    const uint16_t record_segment = seg_r16(cpu->s[CPU_DS],
                                             (uint16_t)(table_offset + 2u));
    const uint16_t record = (uint16_t)(record_offset + product_lo);
    const int8_t tag = (int8_t)seg_r8(record_segment, record);
    const uint16_t count = (tag == 3) ? 18u : ((tag == 7) ? 20u : 21u);
    const uint64_t cycles = (uint64_t)count * 4u;
    const uint16_t old_bp = cpu->r[CPU_BP];
    vm *machine = (vm *)cpu->vm;
    (void)user;

    if (cpu->step_budget_remaining < count) return HOOK_CONTINUE;
    if (machine && (machine->cycles_per_second == 0 ||
        machine->next_tick_cycles <= cpu->cycles ||
        machine->next_tick_cycles - cpu->cycles <= cycles ||
        (machine->sb.dma_active && (machine->sb.dma_end_cycles <= cpu->cycles ||
         machine->sb.dma_end_cycles - cpu->cycles <= cycles))))
        return HOOK_CONTINUE;

    cpu->r[CPU_AX] = 0x0014u;
    alu_imul16(cpu, row);
    cpu->r[CPU_BX] = alu_op(cpu, ALU_ADD, index, index, 16);
    cpu->r[CPU_BX] = alu_op(cpu, ALU_ADD, cpu->r[CPU_BX], cpu->r[CPU_BX], 16);
    cpu->s[CPU_ES] = record_segment;
    cpu->r[CPU_BX] = record_offset;
    cpu->r[CPU_BX] = alu_op(cpu, ALU_ADD, cpu->r[CPU_BX], product_lo, 16);
    cpu->r[CPU_AX] = (uint16_t)(int16_t)tag; /* mov al; cbw */
    cpu->r[CPU_AX] = alu_op(cpu, ALU_SUB, cpu->r[CPU_AX], 3u, 16);
    if (cpu->r[CPU_AX] == 0) {
        cpu->r[CPU_AX] = seg_r16(record_segment, (uint16_t)(record + 10u));
    } else {
        cpu->r[CPU_AX] = alu_op(cpu, ALU_SUB, cpu->r[CPU_AX], 4u, 16);
        if (cpu->r[CPU_AX] == 0) {
            cpu->r[CPU_AX] = seg_r16(record_segment, (uint16_t)(record + 10u));
        } else {
            cpu->r[CPU_AX] = alu_op(cpu, ALU_XOR, 0, 0, 16);
        }
    }
    cpu->r[CPU_BP] = old_bp;
    cpu->cycles += cycles;
    cpu->step_guest_insns = (uint8_t)count;
    g_exe_112853_hits++;
    return HOOK_DID_RETF;
}

/* Lower exe_100016's unchanged return and its flag-clear direct-store path.
 * The flag-set changed-input path retains its two retail helper calls. */
static hook_result_t native_exe_100016(cpu86 *cpu, void *user) {
    const uint16_t entry_sp = cpu->r[CPU_SP];
    const uint16_t saved_bp = cpu->r[CPU_BP];
    const uint16_t arg_a = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 4u));
    const uint16_t arg_b = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 6u));
    const uint16_t global_a = seg_r16(cpu->s[CPU_DS], EXE_100016_GLOBAL_A_DS);
    const uint16_t global_b = seg_r16(cpu->s[CPU_DS], EXE_100016_GLOBAL_B_DS);
    const bool unchanged = arg_a == global_a && arg_b == global_b;
    const uint8_t state = seg_r8(cpu->s[CPU_DS], EXE_100016_FLAGS_DS);
    const unsigned count = unchanged ? 10u : (arg_a == global_a ? 16u : 13u);
    const uint32_t cycles = count * 4u;
    vm *machine = (vm *)cpu->vm;
    (void)user;

    if ((!unchanged && (state & 1u)) || cpu->step_budget_remaining < count)
        return HOOK_CONTINUE;
    /* A frame PUSH must not change any value inspected before accepting
     * the path. Fall back for guest layouts aliasing that slot with DS. */
    for (unsigned i = 0; i < 2u; i++) {
        const uint32_t byte = cpu_lin(cpu->s[CPU_SS], (uint16_t)(entry_sp - 2u + i));
        if (byte == cpu_lin(cpu->s[CPU_DS], EXE_100016_FLAGS_DS))
            return HOOK_CONTINUE;
        for (unsigned j = 0; j < 4u; j++)
            if (byte == cpu_lin(cpu->s[CPU_DS], (uint16_t)(EXE_100016_GLOBAL_A_DS + j)))
                return HOOK_CONTINUE;
    }
    if (machine && (machine->cycles_per_second == 0 ||
        machine->next_tick_cycles <= cpu->cycles ||
        machine->next_tick_cycles - cpu->cycles <= cycles ||
        (machine->sb.dma_active && (machine->sb.dma_end_cycles <= cpu->cycles ||
         machine->sb.dma_end_cycles - cpu->cycles <= cycles))))
        return HOOK_CONTINUE;

    seg_w16(cpu->s[CPU_SS], (uint16_t)(entry_sp - 2u), saved_bp);
    cpu->r[CPU_AX] = global_a;
    (void)alu_op(cpu, ALU_SUB, arg_a, global_a, 16);
    if (arg_a == global_a) {
        cpu->r[CPU_AX] = global_b;
        (void)alu_op(cpu, ALU_SUB, arg_b, global_b, 16);
    }
    if (!unchanged) {
        (void)alu_op(cpu, ALU_AND, state, 1u, 8);
        cpu->r[CPU_AX] = arg_a;
        seg_w16(cpu->s[CPU_DS], EXE_100016_GLOBAL_A_DS, arg_a);
        cpu->r[CPU_AX] = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 6u));
        seg_w16(cpu->s[CPU_DS], EXE_100016_GLOBAL_B_DS, cpu->r[CPU_AX]);
    }
    cpu->r[CPU_BP] = saved_bp;
    cpu->r[CPU_SP] = entry_sp;
    cpu->cycles += cycles;
    cpu->step_guest_insns = (uint8_t)count;
    if (unchanged) g_exe_100016_fast_hits++;
    else g_exe_100016_store_hits++;
    return HOOK_DID_RETF;
}

#ifdef XANTH_NATIVE_STAGE2_TESTING
hook_result_t xanth_native_stage2_test_exe_100016(cpu86 *cpu) {
    return native_exe_100016(cpu, NULL);
}
#endif

/* Lower exe_103774's signed-negative path; nonnegative inputs call a helper. */
static hook_result_t native_exe_103774(cpu86 *cpu, void *user) {
    const uint16_t entry_sp = cpu->r[CPU_SP];
    const uint16_t saved_bp = cpu->r[CPU_BP];
    const uint16_t arg = seg_r16(cpu->s[CPU_SS], (uint16_t)(entry_sp + 4u));
    const uint32_t cycles = 12u * 4u;
    vm *machine = (vm *)cpu->vm;
    (void)user;

    if ((int16_t)arg >= 0 || cpu->step_budget_remaining < 12u)
        return HOOK_CONTINUE;
    if (machine && (machine->cycles_per_second == 0 ||
        machine->next_tick_cycles <= cpu->cycles ||
        machine->next_tick_cycles - cpu->cycles <= cycles ||
        (machine->sb.dma_active && (machine->sb.dma_end_cycles <= cpu->cycles ||
         machine->sb.dma_end_cycles - cpu->cycles <= cycles))))
        return HOOK_CONTINUE;

    (void)alu_op(cpu, ALU_SUB, arg, 0u, 16);
    cpu->r[CPU_AX] = alu_op(cpu, ALU_XOR, 0u, 0u, 16);
    seg_w16(cpu->s[CPU_DS], EXE_103774_GLOBAL_A_DS, cpu->r[CPU_AX]);
    seg_w16(cpu->s[CPU_DS], EXE_103774_GLOBAL_B_DS, cpu->r[CPU_AX]);
    cpu->r[CPU_BP] = saved_bp;
    cpu->r[CPU_SP] = entry_sp;
    cpu->cycles += cycles;
    cpu->step_guest_insns = 12;
    g_exe_103774_negative_hits++;
    return HOOK_DID_RETF;
}

/* Lower exe_100203's four PUSH AX instructions, then resume retail code at CALLF. */
static hook_result_t native_exe_100203_prefix(cpu86 *cpu, void *user) {
    vm *machine = (vm *)cpu->vm;
    const uint32_t cycles = 4u * 4u;
    (void)user;

    if (cpu->step_budget_remaining < 4u) return HOOK_CONTINUE;
    if (machine && (machine->cycles_per_second == 0 ||
        machine->next_tick_cycles <= cpu->cycles ||
        machine->next_tick_cycles - cpu->cycles <= cycles ||
        (machine->sb.dma_active && (machine->sb.dma_end_cycles <= cpu->cycles ||
         machine->sb.dma_end_cycles - cpu->cycles <= cycles))))
        return HOOK_CONTINUE;
    for (unsigned i = 0; i < 4u; i++)
        if (mem_r8(cpu_lin(cpu->s[CPU_CS], (uint16_t)(cpu->ip + i))) != 0x50u)
            return HOOK_CONTINUE;
    if (mem_r8(cpu_lin(cpu->s[CPU_CS], (uint16_t)(cpu->ip + 4u))) != 0x9au)
        return HOOK_CONTINUE;

    for (unsigned i = 0; i < 4u; i++) cpu86_push16(cpu, cpu->r[CPU_AX]);
    cpu->ip = (uint16_t)(cpu->ip + 4u);
    cpu->cycles += cycles;
    cpu->step_guest_insns = 4u;
    g_exe_100203_prefix_hits++;
    return HOOK_DID_SETIP;
}

/* Recovered src/exe_103744.c performs two DS word copies, then RETF. */
static hook_result_t native_exe_103744(cpu86 *cpu, void *user) {
    static const uint8_t expected[] = {
        0xa1, 0x4a, 0x4f, 0xa3, 0x46, 0x4f,
        0xa1, 0x4c, 0x4f, 0xa3, 0x48, 0x4f, 0xcb
    };
    vm *machine = (vm *)cpu->vm;
    const uint32_t cycles = 5u * 4u;
    (void)user;

    if (cpu->step_budget_remaining < 5u) return HOOK_CONTINUE;
    if (machine && (machine->cycles_per_second == 0 ||
        machine->next_tick_cycles <= cpu->cycles ||
        machine->next_tick_cycles - cpu->cycles <= cycles ||
        (machine->sb.dma_active && (machine->sb.dma_end_cycles <= cpu->cycles ||
         machine->sb.dma_end_cycles - cpu->cycles <= cycles))))
        return HOOK_CONTINUE;
    for (size_t i = 0; i < sizeof(expected); i++)
        if (mem_r8(cpu_lin(cpu->s[CPU_CS], (uint16_t)(cpu->ip + i))) != expected[i])
            return HOOK_CONTINUE;

    /* Preserve the retail 16-bit signed globals around the recovered C body. */
    xanth_exe_103744_src0 = (int16_t)seg_r16(cpu->s[CPU_DS], EXE_103744_SRC0_DS_OFFSET);
    xanth_exe_103744_src1 = (int16_t)seg_r16(cpu->s[CPU_DS], EXE_103744_SRC1_DS_OFFSET);
    exe_103744();
    seg_w16(cpu->s[CPU_DS], EXE_103744_DST0_DS_OFFSET,
            (uint16_t)xanth_exe_103744_dst0);
    seg_w16(cpu->s[CPU_DS], EXE_103744_DST1_DS_OFFSET,
            (uint16_t)xanth_exe_103744_dst1);
    cpu->r[CPU_AX] = (uint16_t)xanth_exe_103744_src1;
    cpu->cycles += cycles;
    cpu->step_guest_insns = 5u;
    g_exe_103744_hits++;
    return HOOK_DID_RETF;
}

#ifdef XANTH_NATIVE_STAGE2_TESTING
hook_result_t xanth_native_stage2_test_exe_100203_prefix(cpu86 *cpu) {
    return native_exe_100203_prefix(cpu, NULL);
}
#endif

#ifdef XANTH_NATIVE_STAGE2_TESTING
hook_result_t xanth_native_stage2_test_exe_103774(cpu86 *cpu) {
    return native_exe_103774(cpu, NULL);
}
#endif

#ifdef XANTH_NATIVE_STAGE2_TESTING
hook_result_t xanth_native_stage2_test_exe_103744(cpu86 *cpu) {
    return native_exe_103744(cpu, NULL);
}
#endif

/* Hash only caller-owned loaded bytes; metadata contains no retail byte runs.
 * Masks reproduce the previous byte-comparison exclusions. Their relocated
 * segment values are still checked explicitly by the install routine. */
static bool native_extent_matches(const vm *machine, uint32_t offset, size_t length,
        const char *expected, const uint8_t *mask, size_t mask_count) {
    uint8_t actual[128];
    char digest[65];
    if (length > sizeof(actual)) return false;
    for (size_t i = 0; i < length; i++)
        actual[i] = mem_r8((uint32_t)machine->img.load_seg * 16u + offset + (uint32_t)i);
    for (size_t i = 0; i < mask_count; i++) {
        if (mask[i] >= length) return false;
        actual[mask[i]] = 0;
    }
    return xanth_sha256_buffer(actual, length, digest) && strcmp(digest, expected) == 0;
}

bool xanth_native_stage2_install(vm *machine) {
    static const char verified_body_sha256[] = "81c02e378fa02460494a5ab4b4cc2a52c4e533c630ee0e123431ad9d14fa850d";
    static const char verified_far_ptr_body_sha256[] = "1864a688aea17097677a0f513034575c8b8a811dbc9e54ee9133562669c38898";
    /* SHA-256 of the matched source extent; relocation bytes are zeroed. */
    static const char verified_exe_94712_body_sha256[] = "05db804f8bbab974d30bcf6bcd5bbca6b4ad2c36fd4e5920a96a6afa8e7bf3ec";
    static const char verified_if0_helper_inc_fast_prefix_sha256[] = "cb841d415b4630bf438e5294c5722eec07008ec97e716b6fb589c2d324a23b05";
    static const char verified_exe_14360_body_sha256[] = "3651f67244aeb8699167a4e90f13281b8bb8c3d450728944e557ba59ad2da7c0";
    static const char verified_set_far_arr_body_sha256[] = "c5a3f3b0a0c1facbd39499169c0fe05023c738cd48ceb1bad94f2384339d6662";
    static const char verified_get_far_idx_body_sha256[] = "1a11f57e6cbfc02f4b239013595feb5e90d2f815acaee8dbbce2da78573cb3e3";
    /* SHA-256 of the matched source extent; relocation bytes are zeroed. */
    static const char verified_exe_99679_body_sha256[] = "8efbc35ee63565a4540b3497cc28e1e81547dd70be902ec2791624345e672c25";
    static const char verified_exe_86810_body_sha256[] = "42e9254cc6c044c8cafe5c32a0e059e4a49493142003bf2692a3391a68d299e3";
    static const char verified_exe_84866_body_sha256[] = "b374d005874a0e2712629399afb8d352f82a81f427835c57a9fe82a08dade96c";
    static const char verified_set_int_pair_a_body_sha256[] = "a3f2d87bd0c0805329ab589bcf48bfdd357aeb9bd6a964b093fe827baab6ebe0";
    static const char verified_set_int_pair_b_body_sha256[] = "bf26ead80647fd301b637d8c1b7cce68824f18a6f66c66df6381be3665116b8f";
    static const char verified_set_int_a_body_sha256[] = "3383510bd074067c01f1a4021be5650d3c966cda294d6b638fb8fb6e74e0a7ff";
    static const char verified_set_int_b_body_sha256[] = "e5ad45403cb7c86fd2d8891a7008311dc988c5f14f1db1747b288393879856c3";
    static const char verified_clear_byte_body_sha256[] = "e91ad6f1975a6bc00ed3ca877c258a334c84ae635db57dcf89fc445294abd276";
    static const char verified_swap_int_body_sha256[] = "bf999b0d726f6ca894fa7e0ac389a3156b384aebc84daf8742bbd433927c2aec";
    static const char verified_exe_115346_body_sha256[] = "84c3b76e60f62d494f7455aa3df4e8449d77c6681318e992aedd730a3f89c37d";
    static const char verified_arr_set_one_body_sha256[] = "3a1019e9b0eeefd69771174797f0eb7c22e73ac55f9f77f91317511b203db88f";
    /* SHA-256 of the matched source extent; relocation bytes are zeroed. */
    static const char verified_exe_114942_body_sha256[] = "9c1af8039f71389165d282228ac88fb631b875d7044d10f6974a6e8751d3f58f";
    static const char verified_store_two_globals_body_sha256[] = "aae18fa1b8058585dc7a4cb13f939611a1cf4b81a877f4081bbaea5a0f3ea9e4";
    static const char verified_set_int_if_ge0_body_sha256[] = "2db76bd552a7c40f7933999d24e7850c22b942b2dc32b081fdc2253effcc2d5e";
    static const char verified_iabs_body_sha256[] = "ab0f534abac3b07d0b9e21aeb1ca0cd4c2fdc4d90c3b9637fcc63bc1aeb6f13b";
    /* SHA-256 of the matched source extent; relocation bytes are zeroed. */
    static const char verified_set_far_arr_chk_body_sha256[] = "3f70cb9afdd1fcdadcf351b9a68863deb43f9ee3fae02e1a88b63cdc2489841f";
    static const uint8_t verified_set_byte_one_head[] = {
        0xc6, 0x06, 0x00, 0x00, 0x01, 0xcb
    };
    static const char verified_exe_136552_body_sha256[] = "48348b4cfb92665df981b72550054010b61add90c468e72df33d6cb3a09d49d6";
    static const char verified_exe_52710_body_sha256[] = "8b02b29a20602452d852ce62f20ba2e6652b87344bf6245fa2e9fd7d976f36f5";
    /* SHA-256 of the matched source extent; relocation bytes are zeroed. */
    static const char verified_exe_112795_body_sha256[] = "e07100ae92b59fb11bc8728b2105c4c4b9c433d13f02b3ec94ca4d40ecf78953";
    static const char verified_exe_52674_body_sha256[] = "c4e329c0f5188a9c5c6c7fe0bac6405dc2cb69e410b6c1fce41f7550538dc4bd";
    /* SHA-256 of the matched source extent; relocation bytes are zeroed. */
    static const char verified_exe_112711_body_sha256[] = "8505b71915bdbb5950a0b5ceba723aef93c191f17adb4b68ee9e4aff55c871e2";
    /* SHA-256 of the matched source extent; relocation bytes are zeroed. */
    static const char verified_exe_34775_body_sha256[] = "9c667f698374e7622d75b5781a9b89553bc9d3a8455e7964355f9f3a22db8ada";
    static const uint8_t verified_exe_34775_body_mask[] = {11u, 12u};
    /* SHA-256 of the matched source extent; relocation bytes are zeroed. */
    static const char verified_add_mod_body_sha256[] = "6379a176a2d2506ea182853abaeb9ce0917c10631f1fcb12b862d8dd53a5f59d";
    static const char verified_set_fields_body_sha256[] = "6c2777f4b2a6aa1939705c14fcbbfd8a68b97c2dbc8d4b231020b2f76eeeb5a1";
    /* SHA-256 of the matched source extent; relocation bytes are zeroed. */
    static const char verified_exe_112853_body_sha256[] = "e483c0688892cee7af33649cdba5e9575f5bdd56aae8ba9ec5090279a63e7dc2";
    /* SHA-256 of the matched source extent; relocation bytes are zeroed. */
    static const char verified_exe_100016_body_sha256[] = "72ebbc592e4189f3aef161db85dc4be248105a0eed8233901fda010b859c7f30";
    static const uint8_t verified_exe_100016_body_mask[] = {29u, 30u, 50u, 51u};
    /* SHA-256 of the matched source extent; relocation bytes are zeroed. */
    static const char verified_exe_103774_body_sha256[] = "3e9648e80a9607eaafdf23a90047c8c5e112db688ee2295fc9e22e8899df9f7f";
    static const uint8_t verified_exe_103774_body_mask[] = {36u, 37u};
    static const char verified_exe_100203_head_sha256[] = "a204f67ca982c0618151b4f5762248cb11cd1ef9382b196f13b50cd494fc0c7e";
    static const char verified_exe_103744_body_sha256[] = "ccee99fef6c420fc3af43f1b422fca5d7a073671c406f82508d17d97aa703f6c";
    uint32_t linear;
    uint16_t segment, offset;
    if (!machine) return false;

    if (!native_extent_matches(machine, EXE_136552_OFFSET, 4u,
            verified_exe_136552_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_52710_OFFSET, 10u,
            verified_exe_52710_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_112795_OFFSET, 58u,
            verified_exe_112795_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_52674_OFFSET, 13u,
            verified_exe_52674_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_112711_OFFSET, 84u,
            verified_exe_112711_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_34775_OFFSET, 42u,
            verified_exe_34775_body_sha256, verified_exe_34775_body_mask, sizeof(verified_exe_34775_body_mask))) return false;
    {
        uint32_t segment_word = (uint32_t)machine->img.load_seg * 16u +
                                EXE_34775_OFFSET + 11u;
        uint16_t expected_segment =
            (uint16_t)(machine->img.load_seg + EXE_34775_DATA_SEGMENT);
        if (mem_r8(segment_word) != (uint8_t)expected_segment ||
            mem_r8(segment_word + 1u) != (uint8_t)(expected_segment >> 8))
            return false;
    }
    if (!native_extent_matches(machine, ADD_MOD_EXE_OFFSET, 37u,
            verified_add_mod_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, SET_FIELDS_EXE_OFFSET, 22u,
            verified_set_fields_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_112853_OFFSET, 52u,
            verified_exe_112853_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_100016_OFFSET, 70u,
            verified_exe_100016_body_sha256, verified_exe_100016_body_mask, sizeof(verified_exe_100016_body_mask))) return false;
    for (size_t i = 0; i < 2u; i++) {
        uint32_t address = (uint32_t)machine->img.load_seg * 16u +
                           EXE_100016_OFFSET + (i == 0u ? 29u : 50u);
        uint16_t expected_segment =
            (uint16_t)(machine->img.load_seg + 0x08a7u);
        if (mem_r8(address) != (uint8_t)expected_segment ||
            mem_r8(address + 1u) != (uint8_t)(expected_segment >> 8))
            return false;
    }
    if (!native_extent_matches(machine, EXE_103774_OFFSET, 54u,
            verified_exe_103774_body_sha256, verified_exe_103774_body_mask, sizeof(verified_exe_103774_body_mask))) return false;
    if (!native_extent_matches(machine, EXE_100203_OFFSET, 5u,
            verified_exe_100203_head_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_103744_OFFSET, 13u,
            verified_exe_103744_body_sha256, NULL, 0u)) return false;
    {
        uint32_t address = (uint32_t)machine->img.load_seg * 16u +
                           EXE_103774_OFFSET + 36u;
        uint16_t expected_segment =
            (uint16_t)(machine->img.load_seg + 0x18a5u);
        if (mem_r8(address) != (uint8_t)expected_segment ||
            mem_r8(address + 1u) != (uint8_t)(expected_segment >> 8))
            return false;
    }

    if (!native_extent_matches(machine, SET_INT_AND_ZERO_EXE_OFFSET, 17u,
            verified_body_sha256, NULL, 0u)) return false;

    if (!native_extent_matches(machine, SET_FAR_PTR_EXE_OFFSET, 18u,
            verified_far_ptr_body_sha256, NULL, 0u)) return false;

    if (!native_extent_matches(machine, EXE_94712_EXE_OFFSET, 39u,
            verified_exe_94712_body_sha256, NULL, 0u)) return false;

    if (!native_extent_matches(machine, IF0_HELPER_INC_EXE_OFFSET, 7u,
            verified_if0_helper_inc_fast_prefix_sha256, NULL, 0u)) return false;
    /* The skipped slow branch contains a relocated far-call segment word. */
    if (mem_r8((uint32_t)machine->img.load_seg * 16u +
               IF0_HELPER_INC_EXE_OFFSET + 16u) != 0xcb) return false;

    if (!native_extent_matches(machine, EXE_14360_EXE_OFFSET, 22u,
            verified_exe_14360_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, SET_FAR_ARR_EXE_OFFSET, 26u,
            verified_set_far_arr_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, GET_FAR_IDX_EXE_OFFSET, 29u,
            verified_get_far_idx_body_sha256, NULL, 0u)) return false;
    for (size_t u = 0; u < sizeof(g_exe_37625_units) / sizeof(g_exe_37625_units[0]); u++) {
        const uint8_t signature[] = {
            0xc7, 0x06,
            (uint8_t)g_exe_37625_units[u].global_ds_offset,
            (uint8_t)(g_exe_37625_units[u].global_ds_offset >> 8),
            0x00, 0x00, 0xcb
        };
        for (size_t i = 0; i < sizeof(signature); i++) {
            uint32_t address = (uint32_t)machine->img.load_seg * 16u +
                               g_exe_37625_units[u].exe_offset + (uint32_t)i;
            if (mem_r8(address) != signature[i]) return false;
        }
    }
    if (!native_extent_matches(machine, EXE_99679_EXE_OFFSET, 48u,
            verified_exe_99679_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_86810_EXE_OFFSET, 4u,
            verified_exe_86810_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_84866_EXE_OFFSET, 8u,
            verified_exe_84866_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, SET_INT_PAIR_A_EXE_OFFSET, 17u,
            verified_set_int_pair_a_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, SET_INT_PAIR_B_EXE_OFFSET, 17u,
            verified_set_int_pair_b_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, SET_INT_A_EXE_OFFSET, 11u,
            verified_set_int_a_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, SET_INT_B_EXE_OFFSET, 11u,
            verified_set_int_b_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, CLEAR_BYTE_EXE_OFFSET, 12u,
            verified_clear_byte_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, SWAP_INT_EXE_OFFSET, 25u,
            verified_swap_int_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_115346_OFFSET, 13u,
            verified_exe_115346_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, ARR_SET_ONE_OFFSET, 23u,
            verified_arr_set_one_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, EXE_114942_OFFSET, 50u,
            verified_exe_114942_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, STORE_TWO_GLOBALS_OFFSET, 23u,
            verified_store_two_globals_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, SET_INT_IF_GE0_OFFSET, 17u,
            verified_set_int_if_ge0_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, IABS_OFFSET, 13u,
            verified_iabs_body_sha256, NULL, 0u)) return false;
    if (!native_extent_matches(machine, SET_FAR_ARR_CHK_OFFSET, 40u,
            verified_set_far_arr_chk_body_sha256, NULL, 0u)) return false;
    for (size_t u = 0; u < sizeof(g_set_byte_one_units) / sizeof(g_set_byte_one_units[0]); u++) {
        for (size_t i = 0; i < sizeof(verified_set_byte_one_head); i++) {
            uint8_t expected = verified_set_byte_one_head[i];
            if (i == 2u) expected = (uint8_t)g_set_byte_one_units[u].global_ds_offset;
            if (i == 3u) expected = (uint8_t)(g_set_byte_one_units[u].global_ds_offset >> 8);
            uint32_t address = (uint32_t)machine->img.load_seg * 16u +
                               g_set_byte_one_units[u].exe_offset + (uint32_t)i;
            if (mem_r8(address) != expected) return false;
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
    for (size_t u = 0; u < sizeof(g_exe_37625_units) / sizeof(g_exe_37625_units[0]); u++) {
        linear = (uint32_t)machine->img.load_seg * 16u +
                 g_exe_37625_units[u].exe_offset;
        segment = (uint16_t)(linear >> 4);
        offset = (uint16_t)(linear & 0x0fu);
        if (!cpu86_hook_install(segment, offset, native_exe_37625,
                                (void *)&g_exe_37625_units[u]))
            return false;
    }

    linear = (uint32_t)machine->img.load_seg * 16u + EXE_99679_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_99679_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_99679, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + EXE_86810_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_86810_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_86810, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + EXE_84866_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_84866_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_84866, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + SET_INT_PAIR_A_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_set_int_pair_a_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_set_int_pair, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + SET_INT_PAIR_B_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_set_int_pair_b_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_set_int_pair,
                            (void *)(uintptr_t)1u)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + SET_INT_A_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_set_int_a_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_set_int, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + SET_INT_B_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_set_int_b_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_set_int,
                            (void *)(uintptr_t)1u)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + CLEAR_BYTE_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_clear_byte_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_clear_byte, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + SWAP_INT_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_swap_int_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_swap_int, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + EXE_115346_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_115346_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_115346, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + ARR_SET_ONE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_arr_set_one_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_arr_set_one, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + EXE_114942_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_114942_hits = 0;
    g_exe_114942_negative_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_114942, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + STORE_TWO_GLOBALS_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_store_two_globals_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_store_two_globals, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + SET_INT_IF_GE0_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_set_int_if_ge0_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_set_int_if_ge0, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + IABS_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_iabs_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_iabs, NULL)) return false;

    linear = (uint32_t)machine->img.load_seg * 16u + SET_FAR_ARR_CHK_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_set_far_arr_chk_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_set_far_arr_chk, NULL)) return false;

    g_set_byte_one_hits = 0;
    for (size_t u = 0; u < sizeof(g_set_byte_one_units) / sizeof(g_set_byte_one_units[0]); u++) {
        linear = (uint32_t)machine->img.load_seg * 16u +
                 g_set_byte_one_units[u].exe_offset;
        segment = (uint16_t)(linear >> 4);
        offset = (uint16_t)(linear & 0x0fu);
        if (!cpu86_hook_install(segment, offset, native_set_byte_one,
                                (void *)&g_set_byte_one_units[u]))
            return false;
    }
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_136552_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_136552_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_136552, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_52710_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_52710_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_52710, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_112795_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_112795_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_112795, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_52674_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_52674_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_52674, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_112711_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_112711_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_112711, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_34775_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_34775_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_34775, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + ADD_MOD_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_add_mod_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_add_mod, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + SET_FIELDS_EXE_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_set_fields_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_set_fields, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_112853_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_112853_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_112853, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_100016_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_100016_fast_hits = 0;
    g_exe_100016_store_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_100016, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_103774_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_103774_negative_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_103774, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_100203_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_100203_prefix_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_100203_prefix, NULL)) return false;
    linear = (uint32_t)machine->img.load_seg * 16u + EXE_103744_OFFSET;
    segment = (uint16_t)(linear >> 4);
    offset = (uint16_t)(linear & 0x0fu);
    g_exe_103744_hits = 0;
    if (!cpu86_hook_install(segment, offset, native_exe_103744, NULL)) return false;
    return true;
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

uint64_t xanth_native_exe_86810_hits(void) {
    return g_exe_86810_hits;
}

uint64_t xanth_native_exe_84866_hits(void) {
    return g_exe_84866_hits;
}

uint64_t xanth_native_set_int_pair_a_hits(void) {
    return g_set_int_pair_a_hits;
}

uint64_t xanth_native_set_int_pair_b_hits(void) {
    return g_set_int_pair_b_hits;
}

uint64_t xanth_native_set_int_a_hits(void) {
    return g_set_int_a_hits;
}

uint64_t xanth_native_set_int_b_hits(void) {
    return g_set_int_b_hits;
}

uint64_t xanth_native_clear_byte_hits(void) {
    return g_clear_byte_hits;
}

uint64_t xanth_native_swap_int_hits(void) {
    return g_swap_int_hits;
}

uint64_t xanth_native_exe_115346_hits(void) {
    return g_exe_115346_hits;
}

uint64_t xanth_native_arr_set_one_hits(void) {
    return g_arr_set_one_hits;
}

uint64_t xanth_native_exe_114942_hits(void) {
    return g_exe_114942_hits;
}

uint64_t xanth_native_exe_114942_negative_hits(void) {
    return g_exe_114942_negative_hits;
}

uint64_t xanth_native_store_two_globals_hits(void) {
    return g_store_two_globals_hits;
}

uint64_t xanth_native_set_int_if_ge0_hits(void) {
    return g_set_int_if_ge0_hits;
}

uint64_t xanth_native_iabs_hits(void) {
    return g_iabs_hits;
}

uint64_t xanth_native_set_far_arr_chk_hits(void) {
    return g_set_far_arr_chk_hits;
}

uint64_t xanth_native_set_byte_one_hits(void) {
    return g_set_byte_one_hits;
}

uint64_t xanth_native_exe_136552_hits(void) {
    return g_exe_136552_hits;
}

uint64_t xanth_native_exe_52710_hits(void) {
    return g_exe_52710_hits;
}

uint64_t xanth_native_exe_112795_hits(void) {
    return g_exe_112795_hits;
}

uint64_t xanth_native_exe_52674_hits(void) {
    return g_exe_52674_hits;
}

uint64_t xanth_native_exe_112711_hits(void) {
    return g_exe_112711_hits;
}

uint64_t xanth_native_exe_34775_hits(void) {
    return g_exe_34775_hits;
}

uint64_t xanth_native_add_mod_hits(void) {
    return g_add_mod_hits;
}

uint64_t xanth_native_set_fields_hits(void) { return g_set_fields_hits; }
uint64_t xanth_native_exe_112853_hits(void) { return g_exe_112853_hits; }
uint64_t xanth_native_exe_100016_fast_hits(void) { return g_exe_100016_fast_hits; }
uint64_t xanth_native_exe_100016_store_hits(void) { return g_exe_100016_store_hits; }
uint64_t xanth_native_exe_103774_negative_hits(void) { return g_exe_103774_negative_hits; }
uint64_t xanth_native_exe_100203_prefix_hits(void) { return g_exe_100203_prefix_hits; }
uint64_t xanth_native_exe_103744_hits(void) { return g_exe_103744_hits; }
