extern char __near mbCB32;

int far ovl_300499(void)
{
    _asm {
        xor bh,cl
        or ax,0x321e
        dec ax
        adc mbCB32,bl
    }
}
