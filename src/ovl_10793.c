
int far ovl_10793(void)
{
    _asm {
        push es
        retf
        xor [bp+si],bl
        add cl,bl
    }
}
