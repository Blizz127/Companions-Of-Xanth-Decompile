extern int __near mnCB32;

int far ovl_66063(void)
{
    _asm {
        xor bh,ch
        push es
        push ds
        xor dl,[di]
        add mnCB32,bx
    }
}
