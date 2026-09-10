#include <dos.h>

#pragma intrinsic(_disable, _enable)

char g[1];

void far cli_clear(int a)
{
    _disable();
    g[a] = 0;
    _enable();
}
