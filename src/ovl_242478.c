void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_242478(void)
{
    _asm {
        xor al,[bp+di+0x6c4]
        or ax,ax
        jnz short $+51
        mov ax,0x1a
        push ax
        mov ax,0x5d2e
        push ax
        mov ax,0xffff
        push ax
        call far ptr helper_0
        add sp,0x6
        call far ptr helper_1
        or ax,ax
        jnz short $+22
        mov ax,0x5
        push ax
        mov ax,0x5b4
        mov cx,0x328e
        push cx
        push ax
        call far ptr helper_2
        add sp,0x6
L39:
        retf
    }
}
