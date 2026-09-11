void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_34489(void)
{
    _asm {
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov dx,0x91
        push dx
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov cx,0x92
        push cx
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
        push ax
        mov cx,0x3
        push cx
        mov cx,0x8026
        push cx
        call far ptr helper_1
        add sp,0x6
        xor ax,ax
        push ax
        mov ax,0x4
        push ax
        mov ax,0x8026
        push ax
        call far ptr helper_1
        add sp,0x6
        mov ax,0x25
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x19
        mov dx,0xf035
        retf
    }
}
