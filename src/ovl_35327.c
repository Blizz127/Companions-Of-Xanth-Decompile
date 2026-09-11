void far helper_0(void);
void far helper_1(void);
int far ovl_35327(void)
{
    _asm {
        mov ax,0x1
        push ax
        mov ax,0x127
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+30
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov dx,0x8160
        push dx
        call far ptr helper_1
        add sp,0x6
        mov ax,0x1
        push ax
        xor ax,ax
        jmp short $+23
        nop
L30:
        xor ax,ax
        push ax
        push ax
        mov ax,0x8160
        push ax
        call far ptr helper_1
        add sp,0x6
        mov ax,0x1
        push ax
L44:
        push ax
        mov ax,0x8160
        push ax
        call far ptr helper_1
        add sp,0x6
        mov ax,0x21
        mov dx,0xf035
        retf
    }
}
