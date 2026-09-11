
int far ovl_35797(void)
{
    _asm {
        push es
        retf
        xor [bp+si-0x34fc],bh
    }
}
