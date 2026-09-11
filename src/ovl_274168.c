void far helper_0(void);
int far ovl_274168(void)
{
    _asm {
        mov ax,0x162
        push ax
        mov ax,0x9
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+28
        mov ax,0x164
        push ax
        mov ax,0x165
        push ax
        call far ptr helper_0
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
