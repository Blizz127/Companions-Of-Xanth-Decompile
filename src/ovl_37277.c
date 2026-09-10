#include <dos.h>

void far helper_0(int a, int b);
void far helper_1(int a, int b, int c);

void far * far ovl_37277(void)
{
    helper_0(0x73, 0x12D);
    helper_1(0x73, 1, 0);
    return MK_FP(0xF036, 0x0E);
}
