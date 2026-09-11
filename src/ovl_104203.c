extern int __near mnC332;

int near ovl_104203(void)
{
    _asm {
        xor dl,[di+0x1e07]
        xor cl,bh
        or mnC332,bx
    }
}
