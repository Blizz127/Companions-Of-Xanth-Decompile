void far helper_0(void);
int far ovl_110244(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+35
        mov ax,0x3
        push ax
        mov ax,0x7e
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+8
        mov ax,0x2573
        jmp short $+6
        nop
L1F:
        mov ax,0x257f
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
