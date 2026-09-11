void far helper_0(void);
void far helper_1(void);
int far ovl_246496(void)
{
    _asm {
        mov ax,0xa
        push ax
        mov ax,0x129
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+28
        mov ax,0x128
        push ax
        mov ax,0x138
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x1
        jmp short $+5
        nop
L2E:
        xor ax,ax
L30:
        retf
    }
}
