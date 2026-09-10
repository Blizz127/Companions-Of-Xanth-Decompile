#include <dos.h>

char obj;
int g;
void far * far helper_0(int a, int b, void far *p);
void far helper_1(void far *p, void far *q);

int far ovl_62998(void)
{
    helper_1(MK_FP(0xF012, 0x1C), helper_0(0x43, g, &obj));
    return 1;
}
