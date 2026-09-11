extern int __near mn0016;

int far exe_489(int a)
{
    _asm {
        pushf
        cli
        mov ax,[bp+0x6]
        mov cs:mn0016,ax
        popf
    }
}
