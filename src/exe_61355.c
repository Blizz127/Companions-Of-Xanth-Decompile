extern char __near mb035C;

int far exe_61355(void)
{
    _asm {
        cmp byte ptr mb035C,0x1
        sbb ax,ax
        add ax,0x5a17
        retf
    }
}
