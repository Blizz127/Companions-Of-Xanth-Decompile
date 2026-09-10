#include <dos.h>

int g;
void far * far helper_0(int a, int b);
void far helper_1(void far *p, void far *q);

int far ovl_61918(void)
{
    helper_1(MK_FP(0xF012, 0x3), helper_0(0x1, g));
    return 1;
}
