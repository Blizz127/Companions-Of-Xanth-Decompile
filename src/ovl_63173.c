#include <dos.h>

void far helper_0(void far *p);

int far ovl_63173(void)
{
    helper_0(MK_FP(0xF012, 0x20));
    return 1;
}
