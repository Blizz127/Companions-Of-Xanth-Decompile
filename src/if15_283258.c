#include <dos.h>

void far helper_mkfp(void far *p);
void far helper3(int a, int b, int c);
void far helper2(int a, int b);

int far if15_283258(int a)
{
    if (a == 15) {
        helper_mkfp(MK_FP(0xF03F, 0x12));
        helper3(0x16D, 0x169, 0);
        helper3(0x16E, 0x16C, 1);
        helper2(0x16E, 0x4E);
        return 0x169;
    }
    return 0x169;
}
