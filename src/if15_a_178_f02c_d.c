#include <dos.h>
void far helper_mkfp(void far *p);
int far if15_ret(int a)
{
    if (a != 15)
        return 376;
    helper_mkfp(MK_FP(0xF02C, 0x000D));
    return 0;
}
