
int near ovl_111523(void)
{
    _asm {
        xor dh,[bp+si+0x15]
        push ds
        xor ch,[bx+di+0x1]
        push ds
        xor al,bl
    }
}
