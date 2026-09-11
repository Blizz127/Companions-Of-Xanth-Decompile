
int far ovl_91603(void)
{
    _asm {
        xor dh,[bp+0x1e03]
        xor ch,[bx+di+0x3]
        push ds
        xor cl,bl
    }
}
