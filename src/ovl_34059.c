#include <dos.h>

void far helper_0(int a, int b, int c);

void far * far ovl_34059(void)
{
    helper_0(0x805E, 4, 0);
    return MK_FP(0xF035, 0x10);
}
