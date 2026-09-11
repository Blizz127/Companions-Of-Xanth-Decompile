void far helper_0(void);
void far helper_1(void);
int far ovl_253094(void)
{
    _asm {
        call far ptr helper_0
        or ax,ax
        jz short $+27
        mov ax,0x137
        push ax
        mov ax,0x138
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x1
        jmp short $+4
L22:
        xor ax,ax
L24:
        retf
    }
}
