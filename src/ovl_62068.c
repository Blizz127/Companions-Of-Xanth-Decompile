#include <dos.h>

char obj0, obj1;
int g;
void far * far helper_0(int a, int b, void far *p);
void far helper_1(void far *p, void far *q, void far *r);

int far ovl_62068(void)
{
    helper_1(MK_FP(0xF012, 0x6), helper_0(0x52, g, &obj1), helper_0(0x44, g, &obj0));
    return 1;
}
