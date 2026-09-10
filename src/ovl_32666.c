#include <dos.h>

void far helper(int a, int b, int c);

void far * far ovl_32666(void)
{
    helper(0x801A, 1, 0);
    return MK_FP(0xF034, 0x1A);
}
