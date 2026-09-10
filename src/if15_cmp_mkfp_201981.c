#include <dos.h>

int far helper_ii(int a, int b);
void far helper_mkfp(void far *p);

int far if15_cmp_mkfp(int a)
{
    if (a != 15)
        return 0x132;
    if (!helper_ii(0x11, 0x10C))
        return 0x132;
    helper_mkfp(MK_FP(0xF024, 0x0032));
    return 0;
}
