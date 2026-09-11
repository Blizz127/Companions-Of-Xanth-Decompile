void far helper_0(void);
void far helper_1(void);
int far ovl_169873(void)
{
    _asm {
        xor ax,ax
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+17
        call far ptr helper_1
        or ax,ax
        jnz short $+8
        mov ax,0x1
        jmp short $+5
        nop
L1E:
        xor ax,ax
L20:
        retf
    }
}
