#include <dos.h>
void far helper(int a, int b, int c);
void far * far ovl_41644(void)
{
    helper(0xa4, 0xd, 0);
    return MK_FP(0xf037, 0xf);
}
