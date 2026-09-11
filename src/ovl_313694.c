void far helper_0(void);
void far helper_1(void);
int far ovl_313694(void)
{
    _asm {
        mov ax,0x32
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+8
        mov ax,0x3a27
        jmp short $+6
        nop
L16:
        mov ax,0x3a32
L19:
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
        retf
    }
}
