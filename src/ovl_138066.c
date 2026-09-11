void far helper_0(void);
void far helper_1(void);
int far ovl_138066(void)
{
    _asm {
        xor ax,ax
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+27
        mov ax,0xa3
        push ax
        mov ax,0xa4
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L28:
        xor ax,ax
L2A:
        retf
    }
}
