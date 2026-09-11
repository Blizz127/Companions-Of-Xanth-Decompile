
int far ovl_156415(void)
{
    _asm {
        xor bh,[bp+si]
        or ax,0x321e
        and al,0xf
        push ds
        xor cl,bl
    }
}
