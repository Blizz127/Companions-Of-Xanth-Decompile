
int far ovl_156395(void)
{
    _asm {
        xor ah,cl
        push es
        push ds
        xor dl,[bp+di+0xa]
        push ds
        xor cl,bl
    }
}
