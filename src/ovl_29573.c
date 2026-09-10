#include <dos.h>

char g;

void far * far ovl_29573(void)
{
    g = 1;
    return MK_FP(0xF034, 0);
}
