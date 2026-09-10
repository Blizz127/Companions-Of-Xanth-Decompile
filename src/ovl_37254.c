#include <dos.h>
void far helper(int x, int y);
void far * far ovl_37254(void)
{
    helper(0x7, 0x5);
    return MK_FP(0xf036, 0xd);
}
