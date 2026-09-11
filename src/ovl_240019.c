extern char __near mb5A32;
extern char __near mbC332;

int near ovl_240019(void)
{
    _asm {
        xor dl,[di]
        add mb5A32,bl
        add mbC332,bl
    }
}
