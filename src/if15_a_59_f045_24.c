#include <dos.h>
void far helper_mkfp(void far *p);
int far if15_ret(int a)
{
    if (a != 15)
        return 89;
    helper_mkfp(MK_FP(0xF045, 0x0024));
    return 0;
}
