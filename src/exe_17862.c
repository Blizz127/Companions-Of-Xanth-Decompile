extern int __near mn5812;
extern int __near mn5814;

int far exe_17862(void)
{
    _asm {
        adc dx,0x26
        mov mn5812,ax
        mov mn5814,dx
        mov ax,dx
        and ah,0x7f
        retf
    }
}
