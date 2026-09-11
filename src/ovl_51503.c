
int far ovl_51503(void)
{
    _asm {
        xor ch,[bp+si+0xa]
        push ds
        xor bh,[bp+di+0x1e00]
        xor cl,bl
    }
}
