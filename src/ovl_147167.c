extern char __near mbCB32;

int far ovl_147167(void)
{
    _asm {
        xor dl,[bp+0x9]
        push ds
        xor ch,bh
        or mbCB32,bl
    }
}
