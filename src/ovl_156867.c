
int near ovl_156867(void)
{
    _asm {
        xor al,[bx+di]
        or al,0x1e
        xor bh,[bx+di+0x1e0b]
        xor al,bl
    }
}
