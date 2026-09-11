extern int __near mnDC32;
extern char __near mbCB32;

int far ovl_281719(void)
{
    _asm {
        xor ah,[bx]
        add bx,mnDC32
        add bl,mbCB32
    }
}
