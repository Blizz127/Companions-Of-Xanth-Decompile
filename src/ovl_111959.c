extern int __near mnCB32;

int far ovl_111959(void)
{
    _asm {
        xor bl,[bp+di+0x1e01]
        xor ch,[bx]
        add mnCB32,bx
    }
}
