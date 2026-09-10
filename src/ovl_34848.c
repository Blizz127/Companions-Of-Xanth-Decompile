#include <dos.h>
void far helper(int a, int b, int c);
void far * far ovl_34848(void)
{
    helper(0x8026, 0x13, 0);
    return MK_FP(0xf035, 0x1e);
}
