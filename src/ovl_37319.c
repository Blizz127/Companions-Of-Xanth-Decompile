#include <dos.h>

int far helper_0(void);
void far helper_1(int a, int b, int c);

void far * far ovl_37319(void)
{
    if (helper_0())
        helper_1(0x80FE, 0, 1);
    return MK_FP(0xF036, 0x0F);
}
