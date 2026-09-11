
int far ovl_17044(void)
{
    _asm {
        int 0xa
        retf
        xor [di],dh
        pop es
        retf
    }
}
