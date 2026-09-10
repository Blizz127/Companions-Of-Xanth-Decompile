#include <dos.h>

int far helper(int a, int b);
void far helper_mkfp(void far *p);

int far if15_311925(int a)
{
    if (a != 15)
        return 0x1BD;
    if (helper(0x1BA, 0x0E)) {
        helper_mkfp(MK_FP(0xF048, 0x4C));
        return 0x1BD;
    }
    helper_mkfp(MK_FP(0xF048, 0x4D));
    return 0;
}
