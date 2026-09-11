void far helper_0(void);
int far exe_0(void)
{
    _asm {
        push bp
        call far ptr helper_0
        pop bp
        retf
    }
}
