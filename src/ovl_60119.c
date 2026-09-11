
int far ovl_60119(void)
{
    _asm {
        xor al,[si+0x1]
        push ds
        xor al,[bx+di+0x1e01]
        xor cl,bl
    }
}
