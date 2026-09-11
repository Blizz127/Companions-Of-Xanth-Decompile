
int far exe_94712(int a)
{
    _asm {
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        add ax,ax
        adc dx,dx
        adc ax,ax
        adc dx,dx
        adc ax,ax
        adc dx,dx
        adc ax,ax
        adc dx,dx
        adc ax,ax
        xchg ax,dx
        and dx,0xf
        add ax,[bp+0xa]
        adc dx,[bp+0xc]
    }
}
