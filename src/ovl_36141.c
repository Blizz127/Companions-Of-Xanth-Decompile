#include <dos.h>

char g;

void far * far ovl_36141(void)
{
    g = 1;
    return MK_FP(0xF036, 2);
}
