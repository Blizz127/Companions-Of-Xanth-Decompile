#include <dos.h>

#pragma intrinsic(_disable, _enable)

unsigned g0;
unsigned g1;
unsigned g2;

void far exe_825(void)
{
    _disable();
    g0 = 0x5E7C;
    g1 = 0x5E7C;
    g2 = 0;
    _enable();
}
