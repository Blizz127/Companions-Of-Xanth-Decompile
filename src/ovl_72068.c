void far helper_0(void);
void far helper_1(void);
int far ovl_72068(void)
{
    _asm {
        mov ax,0xe
        push ax
        mov ax,0x31
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+20
        push ax
        call far ptr helper_1
        add sp,0x2
        or ax,ax
        jz short $+7
        mov ax,0x1
        jmp short $+4
L26:
        xor ax,ax
L28:
        retf
    }
}
