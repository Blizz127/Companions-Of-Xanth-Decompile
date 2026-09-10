#include <dos.h>

int g;
char hi;
char lo;
void far helper_mkfp(void far *p, void far *q);

int far if15_288149(int a)
{
    if (a != 15)
        return 0x180;
    if (g >= 4)
        helper_mkfp(MK_FP(0xF02E, 7), &hi);
    else
        helper_mkfp(MK_FP(0xF02E, 7), &lo);
    return 0;
}
