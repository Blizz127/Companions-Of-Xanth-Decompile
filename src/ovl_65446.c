#include <dos.h>

int g0, g1;
void far * far helper_0(int a, int b);
void far helper_1(void far *p0, void far *p1, void far *p2, void far *p3);

int far ovl_65446(void)
{
    helper_1(MK_FP(0xF012, 0x52), helper_0(0x2, g0), helper_0(0x2, g1), helper_0(0x26, g0));
    return 1;
}
