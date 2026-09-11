
int far ovl_8136(void)
{
    _asm {
        mov ah,0x2
        retf
        xor [bx-0x34fe],bl
    }
}
