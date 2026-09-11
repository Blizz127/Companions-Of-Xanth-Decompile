
int near ovl_265771(void)
{
    _asm {
        xor ch,[di+0x4]
        push ds
        xor ch,[bx+di]
        add al,0x1e
        xor al,bl
    }
}
