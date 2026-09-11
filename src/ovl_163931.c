extern char __near mb7F32;

int near ovl_163931(void)
{
    _asm {
        xor bl,bl
        add bl,mb7F32
        add ax,0x321e
        ret
    }
}
