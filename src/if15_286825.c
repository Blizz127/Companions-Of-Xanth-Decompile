#include <dos.h>

int far helper(int a, int b);
void far * far helper2(int a, int b);
void far helper_mkfp(void far *p, void far *q);

int far if15_286825(int a)
{
    if (a != 15)
        return 0x17F;
    if (helper(0x17D, 0x0A))
        return 0x17F;
    helper_mkfp(MK_FP(0xF02C, 0x0C), helper2(0x12, 0x17D));
    return 0;
}
