void far helper_0(void);
int far ovl_70544(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+31
        mov ax,0x56
        push ax
        call far ptr helper_0
        mov sp,bp
        cmp ax,0x110
        jnz short $+7
        mov ax,0x1ea7
        jmp short $+5
L1B:
        mov ax,0x1eb0
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
