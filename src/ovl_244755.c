
int far ovl_244755(void)
{
    _asm {
        xor al,dh
        adc al,0x1e
        xor ah,[si]
        add al,0x1e
        xor cl,bl
    }
}
