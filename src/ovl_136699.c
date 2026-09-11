extern int __near mnC332;

int near ovl_136699(void)
{
    _asm {
        xor ah,[bp+si+0xb]
        push ds
        xor al,[bx+di]
        add bx,mnC332
    }
}
