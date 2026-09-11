
int far ovl_41969(void)
{
    _asm {
        push es
        retf
        xor [bx+di+0x8],ch
        retf
    }
}
