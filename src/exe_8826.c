extern void __near nc0008(void);

int far exe_8826(void)
{
    _asm {
        mov ax,0x1
        push ax
        call nc0008
        retf
    }
}
