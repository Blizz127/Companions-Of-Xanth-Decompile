#include <dos.h>

char g;
void far helper_0(int a, int b, int c);

void far * far ovl_40856(void)
{
    g = 1;
    helper_0(0x9B, 0, 0);
    return MK_FP(0xF037, 0x0C);
}
