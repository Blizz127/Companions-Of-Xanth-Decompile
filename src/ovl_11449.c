void far helper_0(void);
int far ovl_11449(void)
{
    _asm {
        jmp short $+8
        nop
        call far ptr helper_0
L08:
        retf
    }
}
