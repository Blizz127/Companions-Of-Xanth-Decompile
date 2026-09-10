#include <dos.h>

void far helper(int a, int b, int c);

void far * far ovl_36091(void)
{
    helper(3, 0, 0);
    return MK_FP(0xF036, 0);
}
