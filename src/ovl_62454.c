#include <dos.h>

int g0, g1;
void far * far helper_0(int a, int b);
void far helper_1(void far *p, void far *q, void far *r);

int far ovl_62454(void)
{
    helper_1(MK_FP(0xF012, 0xF), helper_0(0x2, g1), helper_0(0x2, g0));
    return 1;
}
