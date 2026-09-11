
int near ovl_312387(void)
{
    _asm {
        xor dh,[bp+di+0xc]
        push ds
        xor dl,[bx+di]
        or ax,0x321e
        ret
    }
}
