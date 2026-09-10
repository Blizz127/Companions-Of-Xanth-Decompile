#include <dos.h>

char g;

void far * far ovl_34817(void)
{
    g = 1;
    return MK_FP(0xF035, 0x1D);
}
