#include <dos.h>
void far helper_mkfp(void far *p);
int far if15_ret(int a)
{
    if (a != 15)
        return 318;
    helper_mkfp(MK_FP(0xF039, 0x0042));
    return 0;
}
