void far helper_0(void);
void far helper_1(void);
int far ovl_113079(void)
{
    _asm {
        xor ax,ax
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jnz short $+21
        push ax
        call far ptr helper_1
        add sp,0x2
        or ax,ax
        jz short $+8
        mov ax,0x1
        jmp short $+5
        nop
L22:
        xor ax,ax
L24:
        retf
    }
}
