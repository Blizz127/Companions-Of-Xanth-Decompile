void far helper(void);
int far if15_95972(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+29
        mov ax,0xe
        push ax
        mov ax,0x5d
        push ax
        call far ptr helper
        mov sp,bp
        cmp ax,0x1
        cmc
        sbb ax,ax
        and ax,0x63
        jmp short $+26
        nop
L21:
        mov ax,0xe
        push ax
        mov ax,0x5d
        push ax
        call far ptr helper
        cmp ax,0x1
        sbb ax,ax
        and al,0x9c
        add ax,0x63
L38:
    }
}
