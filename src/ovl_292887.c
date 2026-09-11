
int near ovl_292887(void)
{
    _asm {
        xor al,ch
        add ax,0x321e
        popf
        add ax,0x321e
        ret
    }
}
