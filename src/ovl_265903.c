
int near ovl_265903(void)
{
    _asm {
        xor al,[di+0x1e0a]
        xor bh,[bx+di+0x4]
        push ds
        xor al,bl
    }
}
