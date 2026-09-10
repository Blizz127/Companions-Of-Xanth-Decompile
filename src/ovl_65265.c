#include <dos.h>

char obj;
int g;
void far * far helper_0(int a, int b, void far *p);
void far * far helper_1(int a, int b);
void far helper_2(void far *p, void far *q, void far *r);

int far ovl_65265(void)
{
    helper_2(MK_FP(0xF012, 0x4E), helper_1(2, g), helper_0(0x54, g, &obj));
    return 1;
}
