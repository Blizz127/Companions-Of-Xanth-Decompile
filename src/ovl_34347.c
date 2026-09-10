#include <dos.h>

char g;
void far helper_0(int a, int b, int c);

void far * far ovl_34347(void)
{
    g = 1;
    helper_0(0x8026, 7, 0);
    return MK_FP(0xF035, 0x15);
}
