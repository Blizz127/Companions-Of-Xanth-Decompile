extern int __near mnE532;
extern int __near mnC332;

int near ovl_65875(void)
{
    _asm {
        xor dh,dh
        add mnE532,bx
        add mnC332,bx
    }
}
