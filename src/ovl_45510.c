#include <dos.h>

void far helper_0(int a, int b, int c);
void far helper_1(int a, int b);

void far * far ovl_45510(void)
{
    helper_0(0x8104, 0, 1);
    helper_1(0x183, 0x0A);
    helper_1(0x182, 0x12);
    return MK_FP(0xF04F, 2);
}
