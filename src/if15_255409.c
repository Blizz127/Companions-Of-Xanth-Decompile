void far helper(void);
void far helper2(void);
int far if15_255409(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+41
        mov ax,0x11
        push ax
        mov ax,0x127
        push ax
        call far ptr helper
        mov sp,bp
        or ax,ax
        jnz short $+22
        mov ax,0x5a03
        push ax
        mov ax,0x16f
        push ax
        call far ptr helper2
        mov sp,bp
        xor ax,ax
        jmp short $+6
        nop
L2D:
        mov ax,0x139
L30:
    }
}
