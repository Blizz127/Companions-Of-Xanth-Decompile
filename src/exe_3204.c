
int near exe_3204(void)
{
    _asm {
        and bh,0xe0
        cmp bh,0xc0
        jnz short $+4
        clc
        ret
L0A:
    }
}
