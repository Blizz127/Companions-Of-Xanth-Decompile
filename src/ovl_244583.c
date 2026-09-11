extern char __near mbDC32;
extern char __near mbC332;

int near ovl_244583(void)
{
    _asm {
        xor ch,dh
        or bl,mbDC32
        or bl,mbC332
    }
}
