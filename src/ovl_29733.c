#include <dos.h>

char g;

void far * far ovl_29733(void)
{
    g = 1;
    return MK_FP(0xF034, 4);
}
