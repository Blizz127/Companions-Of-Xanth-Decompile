#include <dos.h>

char g;
void far helper_0(void);
void far helper_1(void);

void far * far ovl_38629(void)
{
    g = 1;
    helper_0();
    helper_1();
    return MK_FP(0xF036, 0x1B);
}
