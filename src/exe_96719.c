extern int __near mn63E0;

int far exe_96719(void)
{
    _asm {
        mov ax,mn63E0
        sub dx,dx
        add ax,ax
        adc dx,dx
        add ax,ax
        adc dx,dx
        add ax,ax
        adc dx,dx
        add ax,ax
        adc dx,dx
        mov word ptr mn63E0,0xffff
        retf
    }
}
