#include <dos.h>
void far helper_mkfp(void far *p);
int far if15_ret(int a)
{
    if (a != 15)
        return 440;
    helper_mkfp(MK_FP(0xF049, 0x005B));
    return 0;
}
