void far helper(void);
int far exe_83573(int a)
{
    _asm {
        sub sp,0x2
        mov ax,0x1
        push ax
        lea ax,[bp-0x2]
        push ss
        push ax
        push word ptr [bp+0x6]
        call far ptr helper
        add sp,0x8
        or ax,ax
        jz short $+8
        mov ax,[bp-0x2]
        jmp short $+6
        nop
L21:
        mov ax,0xffff
L24:
    }
}
