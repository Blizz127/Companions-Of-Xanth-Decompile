/*
 * Zero the word a far pointer addresses, with interrupts disabled and the
 * caller's flags preserved. Retail saves flags with `pushf` and restores them
 * with `popf`; no CL 8.00c intrinsic or header provides that pair, so it is
 * written as two single-instruction `_asm` blocks around ordinary C.
 *
 * exe-code:0x830, 16 bytes.
 */
#include <dos.h>

#pragma intrinsic(_disable)

void far exe_2096(unsigned far *p)
{
    _asm { pushf }
    _disable();
    *p = 0;
    _asm { popf }
}
