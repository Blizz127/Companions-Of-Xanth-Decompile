void far helper_0(void);
void far helper_1(void);
int far ovl_258830(void)
{
    _asm {
        mov ax,0xe
        push ax
        mov ax,0x144
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+28
        mov ax,0x1
        push ax
        mov ax,0x145
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
