#include <dos.h>
void far helper(int a, int b, int c);
void far * far ovl_37293(void)
{
    helper(0x73, 0x1, 0);
    return MK_FP(0xf036, 0xe);
}
