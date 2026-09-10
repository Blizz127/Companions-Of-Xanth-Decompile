#include <dos.h>

char g;

void far * far ovl_30359(void)
{
    g = 1;
    return MK_FP(0xF034, 8);
}
