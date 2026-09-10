#include <dos.h>
void far helper_mkfp(void far *p);
int far if15_call_ret(int a)
{
    if (a == 15)
        helper_mkfp(MK_FP(0xF047, 0x0021));
    return 407;
}
