#include <dos.h>

int g0, g1;
void far * far helper_0(int a, int b);
void far helper_1(void far *p, void far *q, void far *r);

int far ovl_63567(void)
{
    helper_1(MK_FP(0xF012, 0x2A), helper_0(0x3, g1), helper_0(0x3, g0));
    return 1;
}
