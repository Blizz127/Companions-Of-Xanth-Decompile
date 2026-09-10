#include <dos.h>
void far helper(int x, int y);
void far * far ovl_45545(void)
{
    helper(0x182, 0x12);
    return MK_FP(0xf04f, 0x2);
}
