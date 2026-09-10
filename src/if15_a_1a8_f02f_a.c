#include <dos.h>
void far helper_mkfp(void far *p);
int far if15_ret(int a)
{
    if (a != 15)
        return 424;
    helper_mkfp(MK_FP(0xF02F, 0x000A));
    return 0;
}
