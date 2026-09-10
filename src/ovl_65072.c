#include <dos.h>

void far helper_0(void far *p);

int far ovl_65072(void)
{
    helper_0(MK_FP(0xF012, 0x4A));
    return 1;
}
