void far helper_0(void);
int far exe_50349(int a)
{
    _asm {
        sub sp,0x2
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x2
        mov [bp-0x2],ax
        or ax,ax
        jz short $+36
L15:
        mov ax,[bp+0x8]
        cmp [bp-0x2],ax
        jz short $+22
        push word ptr [bp-0x2]
        call far ptr helper_0
        add sp,0x2
        mov [bp-0x2],ax
        or ax,ax
        jnz short $-24
        jmp short $+8
L31:
        mov ax,0x1
        jmp short $+5
        nop
L37:
        xor ax,ax
L39:
    }
}
