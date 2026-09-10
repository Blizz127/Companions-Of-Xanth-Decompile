#include <dos.h>

void far helper_0(int a, int b, int c);
void far helper_1(int a, int b);

void far * far ovl_37222(void)
{
    helper_0(3, 0, 0);
    helper_0(0x73, 0, 0);
    helper_1(7, 5);
    return MK_FP(0xF036, 0x0D);
}
