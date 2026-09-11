
int far ovl_196499(void)
{
    _asm {
        xor ah,[bp+di]
        add al,0x1e
        xor dh,[bx+si+0x1e0c]
        xor cl,bl
    }
}
