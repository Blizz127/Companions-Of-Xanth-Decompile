void far helper_0(void);
int far ovl_116797(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+31
        mov ax,0x88
        push ax
        call far ptr helper_0
        mov sp,bp
        cmp ax,0x147
        jnz short $+7
        mov ax,0x2608
        jmp short $+5
L1B:
        mov ax,0x2611
L1E:
        mov dx,ds
        jmp short $+6
        nop
L23:
        xor ax,ax
        cwd
L26:
    }
}
