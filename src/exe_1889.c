#include <dos.h>

#pragma intrinsic(_disable, _enable)

int g;

int far exe_1889(void)
{
    int old;

    _disable();
    old = g;
    g = 0;
    _enable();
    return old;
}
