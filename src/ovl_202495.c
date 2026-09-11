
int near ovl_202495(void)
{
    _asm {
        xor al,[bp+di+0x1e01]
        xor dl,[bp+0x8]
        push ds
        xor al,bl
    }
}
