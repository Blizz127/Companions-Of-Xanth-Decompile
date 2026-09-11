
int far ovl_1645(void)
{
    _asm {
        push es
        retf
        xor [bx+di-0x3500],dh
    }
}
