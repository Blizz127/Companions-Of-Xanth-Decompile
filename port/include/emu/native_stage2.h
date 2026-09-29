#ifndef XANTH_NATIVE_STAGE2_H
#define XANTH_NATIVE_STAGE2_H

#include "vm.h"

#include <stdbool.h>
#include <stdint.h>

/* Install exact source-backed native replacements for verified retail units. */
bool xanth_native_stage2_install(vm *machine);
uint64_t xanth_native_set_int_and_zero_hits(void);
uint64_t xanth_native_set_far_ptr_hits(void);
uint64_t xanth_native_exe_94712_hits(void);
uint64_t xanth_native_if0_helper_inc_hits(void);
uint64_t xanth_native_exe_14360_hits(void);
uint64_t xanth_native_set_far_arr_hits(void);
uint64_t xanth_native_get_far_idx_hits(void);
uint64_t xanth_native_exe_37625_hits(void);
uint64_t xanth_native_exe_99679_hits(void);
uint64_t xanth_native_exe_86810_hits(void);
uint64_t xanth_native_exe_84866_hits(void);
uint64_t xanth_native_set_int_pair_a_hits(void);
uint64_t xanth_native_set_int_pair_b_hits(void);
uint64_t xanth_native_set_int_a_hits(void);
uint64_t xanth_native_set_int_b_hits(void);
uint64_t xanth_native_clear_byte_hits(void);
uint64_t xanth_native_swap_int_hits(void);
uint64_t xanth_native_exe_115346_hits(void);
uint64_t xanth_native_arr_set_one_hits(void);
uint64_t xanth_native_exe_114942_hits(void);
uint64_t xanth_native_exe_114942_negative_hits(void);
#ifdef XANTH_NATIVE_STAGE2_TESTING
hook_result_t xanth_native_stage2_test_exe_114942(cpu86 *cpu);
#endif
uint64_t xanth_native_store_two_globals_hits(void);
uint64_t xanth_native_set_int_if_ge0_hits(void);
uint64_t xanth_native_iabs_hits(void);
uint64_t xanth_native_set_far_arr_chk_hits(void);
uint64_t xanth_native_set_byte_one_hits(void);
uint64_t xanth_native_exe_136552_hits(void);
uint64_t xanth_native_exe_52710_hits(void);
uint64_t xanth_native_exe_112795_hits(void);
uint64_t xanth_native_exe_52674_hits(void);
uint64_t xanth_native_exe_112711_hits(void);
uint64_t xanth_native_exe_34775_hits(void);
uint64_t xanth_native_add_mod_hits(void);
uint64_t xanth_native_set_fields_hits(void);
uint64_t xanth_native_exe_112853_hits(void);
uint64_t xanth_native_exe_100016_fast_hits(void);

#endif
