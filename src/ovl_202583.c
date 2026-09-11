
int far ovl_202583(void)
{
    _asm {
        xor bl,dh
        add al,0x1e
        xor ah,[si]
        add al,0x1e
        xor cl,bl
    }
}
