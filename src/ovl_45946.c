#include <dos.h>
void far helper(int a, int b, int c);
void far * far ovl_45946(void)
{
    helper(0x1db, 0x1d5, 0);
    return MK_FP(0xf04f, 0x4);
}
