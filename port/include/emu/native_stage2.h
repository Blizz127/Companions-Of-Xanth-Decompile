#ifndef XANTH_NATIVE_STAGE2_H
#define XANTH_NATIVE_STAGE2_H

#include "vm.h"

#include <stdbool.h>
#include <stdint.h>

/* Install exact source-backed native replacements for verified retail units. */
bool xanth_native_stage2_install(vm *machine);
uint64_t xanth_native_set_int_and_zero_hits(void);
uint64_t xanth_native_set_far_ptr_hits(void);

#endif
