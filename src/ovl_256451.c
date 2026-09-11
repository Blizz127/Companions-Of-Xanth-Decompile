extern char __near mbDD32;
extern int __near mnCB32;

int far ovl_256451(void)
{
    _asm {
        xor ah,[bx+si]
        or bl,mbDD32
        or mnCB32,bx
    }
}
