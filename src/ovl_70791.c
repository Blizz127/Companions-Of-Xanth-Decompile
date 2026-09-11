extern char __near mbCB32;

int far ovl_70791(void)
{
    _asm {
        xor dl,[di+0x9]
        push ds
        xor dl,bl
        or mbCB32,bl
    }
}
