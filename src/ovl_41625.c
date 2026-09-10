#include <dos.h>

void far helper_0(int a, int b, int c);

void far * far ovl_41625(void)
{
    helper_0(0xA5, 0x0D, 0);
    helper_0(0xA4, 0x0D, 0);
    return MK_FP(0xF037, 0x0F);
}
