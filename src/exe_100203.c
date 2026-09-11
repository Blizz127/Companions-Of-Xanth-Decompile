void far helper_0(void);
int far exe_100203(void)
{
    _asm {
        push ax
        push ax
        push ax
        push ax
        call far ptr helper_0
        add sp,0x8
        retf
    }
}
