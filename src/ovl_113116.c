void far helper_0(void);
void far helper_1(void);
int far ovl_113116(void)
{
    _asm {
        xor ax,ax
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+23
        xor ax,ax
        push ax
        call far ptr helper_1
        add sp,0x2
        or ax,ax
        jz short $+8
        mov ax,0x1
        jmp short $+5
        nop
L24:
        xor ax,ax
L26:
        retf
    }
}
