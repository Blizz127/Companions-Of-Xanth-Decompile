
int far ovl_292939(void)
{
    _asm {
        xor bh,[di+0x1e00]
        xor bl,[bx+0x2]
        push ds
        xor cl,bl
    }
}
