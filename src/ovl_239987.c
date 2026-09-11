
int far ovl_239987(void)
{
    _asm {
        xor dh,[di]
        push es
        push ds
        xor al,[bx+si]
        push es
        push ds
        xor cl,bl
    }
}
