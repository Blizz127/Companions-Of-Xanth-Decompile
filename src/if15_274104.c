void far helper(void);
int far if15_274104(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jz short $+29
        mov ax,0x8
        push ax
        mov ax,0x15f
        push ax
        call far ptr helper
        mov sp,bp
        cmp ax,0x1
        cmc
        sbb ax,ax
        and ax,0x178
        jmp short $+27
        nop
L21:
        mov ax,0x8
        push ax
        mov ax,0x15f
        push ax
        call far ptr helper
        cmp ax,0x1
        sbb ax,ax
        and ax,0xfe87
        add ax,0x178
L39:
    }
}
