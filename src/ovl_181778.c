void far helper_0(void);
int far ovl_181778(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+33
        mov ax,0x12
        push ax
        push word ptr [bp+0x8]
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x2f82
        jmp short $+5
L1D:
        mov ax,0x2f8e
L20:
        mov dx,ds
        jmp short $+6
        nop
L25:
        xor ax,ax
        cwd
L28:
    }
}
