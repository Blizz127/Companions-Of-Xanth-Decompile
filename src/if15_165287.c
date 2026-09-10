#include <dos.h>

int g;
void far helper_mkfp(void far *p);

int far if15_165287(int a)
{
    if (a != 15)
        return 0xBE;
    if (g == 5)
        helper_mkfp(MK_FP(0xF01A, 4));
    else
        helper_mkfp(MK_FP(0xF01A, 5));
    return 0;
}
