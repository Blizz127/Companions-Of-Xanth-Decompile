#include <dos.h>

int g;
char obj;
void far helper(void far *p);

void far ovl_29475(void)
{
    if (g == 0)
        helper(&obj);
}
