extern int __near mnCB32;

int far ovl_60371(void)
{
    _asm {
        xor dl,[bx+si+0x1e0a]
        xor ah,[bx+si]
        or bx,mnCB32
    }
}
