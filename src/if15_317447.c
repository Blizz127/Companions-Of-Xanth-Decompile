#include <dos.h>

char obj;
int far helper(int a, int b);
void far helper_mkfp(void far *p);
void far helper2(void far *p);
void far * far helper3(int a, int b);
void far helper_mkfp2(void far *p, void far *q);

int far if15_317447(int a)
{
    if (a != 15)
        return 0x1CE;
    if (helper(0x1BE, 0x0E)) {
        helper_mkfp(MK_FP(0xF049, 0x5C));
        helper2(&obj);
        return 0x1CE;
    }
    helper_mkfp2(MK_FP(0xF049, 0x5D), helper3(0x12, 0x1BE));
    return 0;
}
