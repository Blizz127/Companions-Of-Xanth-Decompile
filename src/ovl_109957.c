void far helper_0(void);
int far ovl_109957(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+35
        mov ax,0xa
        push ax
        mov ax,0x7d
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+8
        mov ax,0x2556
        jmp short $+6
        nop
L1F:
        mov ax,0x2560
L22:
        mov dx,ds
        jmp short $+6
        nop
L27:
        xor ax,ax
        cwd
L2A:
    }
}
