#include <dos.h>

long far h1(int a, int b);
void far h2(void far *p, long c);

void far mkfp_h1(int v)
{
    h2(MK_FP(0xF007, 0x0005), h1(0x21, v));
}
