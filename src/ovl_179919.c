extern char __near mbC332;

int near ovl_179919(void)
{
    _asm {
        xor ah,[bx+0x1e01]
        xor bh,bl
        add mbC332,bl
    }
}
