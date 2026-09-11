extern int __near mn8132;
extern int __near mnCB32;

int far ovl_156971(void)
{
    _asm {
        xor dl,[bx+di]
        add bx,mn8132
        add mnCB32,bx
    }
}
