#include <dos.h>

int far helper(int a, int b);
void far helper_mkfp(void far *p);

int far if15_302913(int a)
{
    if (a != 15)
        return 0x19C;
    if (helper(0x19B, 0x0E)) {
        helper_mkfp(MK_FP(0xF047, 0x1F));
        return 0x19C;
    }
    helper_mkfp(MK_FP(0xF047, 0x20));
    return 0;
}
