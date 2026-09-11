
int far ovl_29072(void)
{
    _asm {
        or byte ptr [bx+di],0xcb
        xor [bp+si+0xb],bh
        retf
    }
}
