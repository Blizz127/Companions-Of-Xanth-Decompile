
int near ovl_257175(void)
{
    _asm {
        xor al,[bx+si+0x1e05]
        xor cl,[bp+si+0x3]
        push ds
        xor al,bl
    }
}
