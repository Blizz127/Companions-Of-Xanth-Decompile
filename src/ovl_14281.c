extern char __near mbCB08;

int far ovl_14281(void)
{
    _asm {
        push es
        retf
        xor mbCB08,cl
    }
}
