
int far ovl_51711(void)
{
    _asm {
        xor ah,[si+0x6]
        push ds
        xor ch,dh
        or al,0x1e
        xor cl,bl
    }
}
