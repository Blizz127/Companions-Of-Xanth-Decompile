#include <dos.h>
void far helper(int a, int b);

#pragma optimize("g", on)
#pragma optimize("s", off)
void far exe_117451(int a, int b, char far *p)
{
    char saved;

    if (FP_OFF(p) > (unsigned)a) {
        saved = *p;
        *p = 0;
        helper(a, b);
        *p = saved;
    }
}
