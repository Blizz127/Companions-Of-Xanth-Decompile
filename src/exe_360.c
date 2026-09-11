extern int __near mn0008;
extern int __near mn0006;
void far helper_0(void);
int far exe_360(int a)
{
    _asm {
        mov ax,[bp+0x6]
        pushf
        cli
        mov cs:mn0008,ax
        cmp ax,0x1
        mov word ptr cs:mn0006,0x0
        adc word ptr cs:mn0006,0x0
        call far ptr helper_0
        popf
    }
}
