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
uint64_t xanth_native_store_two_globals_hits(void);

#endif
