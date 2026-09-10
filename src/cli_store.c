#include <dos.h>

#pragma intrinsic(_disable, _enable)

int g0;
int g1;

void far cli_store(int a, int b)
{
    _disable();
    g0 = a;
    g1 = b;
    _enable();
}
