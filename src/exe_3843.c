
int near exe_3843(void)
{
    _asm {
        sub dl,0x4
        in al,dx
        pop cx
        clc
        ret
    }
}
