extern char __near mbC332;

int near ovl_142963(void)
{
    _asm {
        xor bh,[bp+si+0x8]
        push ds
        xor al,[di]
        or mbC332,bl
    }
}
