extern void __near nc0011(void);

int far exe_6253(void)
{
    _asm {
        call nc0011
        mov ax,0xffff
        cwd
        mov sp,bp
        pop bp
        retf
    }
}
