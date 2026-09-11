
int near ovl_306943(void)
{
    _asm {
        xor dh,[bx]
        pop es
        push ds
        xor al,[bp+si+0x1e0c]
        xor al,bl
    }
}
