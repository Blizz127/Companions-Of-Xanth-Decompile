void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_242131(void)
{
    _asm {
        mov ax,0xd
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0x5b00
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x19
        push ax
        mov ax,0x5b01
        push ax
        mov ax,0xffff
        push ax
        call far ptr helper_2
        add sp,0x6
        call far ptr helper_3
        or ax,ax
        jnz short $+46
        mov ax,0xa
        push ax
        mov ax,0x3a4
        mov cx,0x328e
        push cx
        push ax
        call far ptr helper_4
        add sp,0x6
        or ax,ax
        jnz short $+22
        mov ax,0x3b
        push ax
        mov ax,0x5b1a
        push ax
        mov ax,0xffff
        push ax
        call far ptr helper_2
        add sp,0x6
L61:
        retf
    }
}
