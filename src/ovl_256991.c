extern int __near mnCB32;

int far ovl_256991(void)
{
    _asm {
        xor dl,[bp+si]
        or al,0x1e
        xor ch,ah
        or bx,mnCB32
    }
}
