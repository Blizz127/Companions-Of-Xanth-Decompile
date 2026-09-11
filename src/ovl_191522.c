void far helper_0(void);
int far ovl_191522(void)
{
    _asm {
        mov ax,0xd9
        push ax
        call far ptr helper_0
        add sp,0x2
        cmp ax,0x156
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L16:
        xor ax,ax
L18:
        retf
    }
}
