#include <dos.h>
void far helper(int a, int b, int c);
void far * far ovl_34700(void)
{
    helper(0x8026, 0x6, 0);
    return MK_FP(0xf035, 0x1c);
}
