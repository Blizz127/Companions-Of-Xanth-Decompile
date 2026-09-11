
int far ovl_285559(void)
{
    _asm {
        xor bh,[bx+di+0x1e00]
        xor al,[bp+0xb]
        push ds
        xor cl,bl
    }
}
