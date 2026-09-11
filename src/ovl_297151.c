extern int __near mnED32;
extern char __near mbC332;

int near ovl_297151(void)
{
    _asm {
        xor al,[bx+di]
        add mnED32,bx
        add mbC332,bl
    }
}
