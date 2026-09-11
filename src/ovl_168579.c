
int near ovl_168579(void)
{
    _asm {
        xor al,[bx+0x1e0b]
        xor dl,[bx+si]
        or ax,0x321e
        ret
    }
}
