#include <dos.h>

int g;
int far helper(int a, int b);
void far helper_mkfp(void far *p);

#pragma optimize("g", on)
int far if15_322519(int a)
{
    if (a != 15)
        return 0x1F0;
    if (helper(0x1DC, g)) {
        helper_mkfp(MK_FP(0xF04B, 0x29));
        return 0x1F0;
    }
    helper_mkfp(MK_FP(0xF04B, 0x2A));
    return 0;
}
