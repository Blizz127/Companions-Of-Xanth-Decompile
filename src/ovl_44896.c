
int far ovl_44896(void)
{
    _asm {
        xor al,[bp+si]
        retf
        xor [bx+di-0x34fe],dh
    }
}
