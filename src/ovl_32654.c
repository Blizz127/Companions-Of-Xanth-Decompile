#include <dos.h>

char g;

void far * far ovl_32654(void)
{
    g = 1;
    return MK_FP(0xF034, 0x19);
}
