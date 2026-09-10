#include <dos.h>

void far helper_0(int a, int b, int c);
void far helper_1(int a, int b, int c);

void far * far ovl_34829(void)
{
    helper_0(0xFA, 1, 0);
    helper_1(0x8026, 0x13, 0);
    return MK_FP(0xF035, 0x1E);
}
