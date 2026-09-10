#include <dos.h>

void far helper_0(int a, int b, int c);

void far * far ovl_45857(void)
{
    helper_0(0x1DC, 0, 0);
    helper_0(0x1DD, 0, 0);
    helper_0(5, 0x1F0, 0);
    helper_0(4, 0x1F0, 0);
    helper_0(0x1DA, 0x1D5, 0);
    helper_0(0x1DB, 0x1D5, 0);
    return MK_FP(0xF04F, 4);
}
