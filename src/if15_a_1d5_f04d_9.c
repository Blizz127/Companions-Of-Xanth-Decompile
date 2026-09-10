#include <dos.h>
void far helper_mkfp(void far *p);
int far if15_ret(int a)
{
    if (a != 15)
        return 469;
    helper_mkfp(MK_FP(0xF04D, 0x0009));
    return 0;
}
