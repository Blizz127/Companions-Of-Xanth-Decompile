#include <dos.h>

void far helper_0(void far *p);

int far ovl_64767(void)
{
    helper_0(MK_FP(0xF012, 0x44));
    return 1;
}
