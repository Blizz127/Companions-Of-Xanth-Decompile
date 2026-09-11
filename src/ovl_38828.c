
int far ovl_38828(void)
{
    _asm {
        mov al,0xa
        retf
        xor [di+0x8],bh
        retf
    }
}
