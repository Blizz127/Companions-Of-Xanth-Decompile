#include <dos.h>

void far helper_0(int a, int b, int c);

void far * far ovl_34436(void)
{
    helper_0(0x8026, 3, 0);
    helper_0(0x8026, 4, 1);
    return MK_FP(0xF035, 0x17);
}
