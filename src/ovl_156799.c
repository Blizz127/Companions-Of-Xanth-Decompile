extern int __near mnD432;
extern char __near mbC332;

int near ovl_156799(void)
{
    _asm {
        xor bl,bl
        adc bx,mnD432
        add bl,mbC332
    }
}
