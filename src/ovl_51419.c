extern char __near mbCB32;

int far ovl_51419(void)
{
    _asm {
        xor dh,[si+0xb]
        push ds
        xor dl,bl
        or bl,mbCB32
    }
}
