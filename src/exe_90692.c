void far helper_0(void);
void far helper_1(void);
int far exe_90692(void)
{
    _asm {
        call far ptr helper_0
        or ax,ax
        jz short $+9
        call far ptr helper_1
        jmp short $+4
L10:
        xor ax,ax
L12:
        retf
    }
}
