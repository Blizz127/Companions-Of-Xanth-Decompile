#include <dos.h>

int far helper_ii(int a, int b);
void far helper_mkfp(void far *p);

int far if15_cmp_mkfp(int a)
{
    if (a != 15)
        return 0x59;
    if (!helper_ii(0x34, 0x0E))
        return -1;
    helper_mkfp(MK_FP(0xF004, 0x004B));
    return 0;
}
