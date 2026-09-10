#include <dos.h>

char g;

void far helper_mkfp(void far *p);

int far if15_g0(int a)
{
    if (a != 15)
        return 0xCD;
    if (g == 0)
        return 0xCD;
    helper_mkfp(MK_FP(0xF01F, 0x002C));
    return 0;
}
