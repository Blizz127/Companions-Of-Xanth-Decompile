#include <dos.h>

int g;

void far * far ovl_45767(void)
{
    g = 0;
    return MK_FP(0xF04F, 3);
}
