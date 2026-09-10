#include <dos.h>

#pragma optimize("g", on)
#pragma optimize("s", off)

char g;
void far helper(int a);

void far * far ovl_34412(void)
{
    helper(0x25);
    g = 1;
    return MK_FP(0xF035, 0x16);
}
