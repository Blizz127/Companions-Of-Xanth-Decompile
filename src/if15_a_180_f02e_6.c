#include <dos.h>
void far helper_mkfp(void far *p);
int far if15_ret(int a)
{
    if (a != 15)
        return 384;
    helper_mkfp(MK_FP(0xF02E, 0x0006));
    return 0;
}
