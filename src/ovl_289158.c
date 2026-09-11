extern int __near mn02E0;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far ovl_289158(void)
{
    _asm {
        mov word ptr mn02E0,0x4
        mov ax,0xa
        push ax
        mov ax,0x182
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x26
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x27
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0xb
        push ax
        call far ptr helper_2
        add sp,0x2
        call far ptr helper_3
        mov ax,0x18
        mov dx,0xf02e
        push dx
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0x19
        mov dx,0xf02e
        push dx
        push ax
        call far ptr helper_5
        add sp,0x4
        mov ax,0x1
        push ax
        push ax
        mov cx,0xa
        push cx
        call far ptr helper_6
        add sp,0x6
        mov ax,0x9
        push ax
        call far ptr helper_7
        add sp,0x2
        mov ax,0x1a
        mov dx,0xf02e
        push dx
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0x3
        push ax
        call far ptr helper_7
        add sp,0x2
        mov ax,0x184
        push ax
        call far ptr helper_8
        add sp,0x2
        mov ax,0x1
        retf
    }
}
