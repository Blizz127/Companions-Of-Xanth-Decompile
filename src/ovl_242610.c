void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_242610(void)
{
    _asm {
        mov ax,0xd
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0x5f00
        push ax
        call far ptr helper_1
        add sp,0x2
        call far ptr helper_2
        or ax,ax
        jnz short $+58
        mov ax,0x8
        push ax
        mov ax,0x6a4
        mov cx,0x328e
        push cx
        push ax
        call far ptr helper_3
        add sp,0x6
        or ax,ax
        jnz short $+34
        mov ax,0x34
        push ax
        mov ax,0x5f02
        push ax
        mov ax,0x5f01
        push ax
        call far ptr helper_4
        add sp,0x6
        mov ax,0x7d0
        push ax
        call far ptr helper_5
        add sp,0x2
L59:
        retf
    }
}
