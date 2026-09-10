#include <dos.h>

void far * far ovl_30015(void)
{
    return MK_FP(0xf034, 0x6);
}
