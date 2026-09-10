#include <dos.h>

char g;

void far * far ovl_30371(void)
{
    g = 1;
    return MK_FP(0xF034, 9);
}
