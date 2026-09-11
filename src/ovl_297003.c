extern int __near mn7532;
extern int __near mnCB32;

int far ovl_297003(void)
{
    _asm {
        xor cl,[bx+di]
        add mn7532,bx
        add bx,mnCB32
    }
}
