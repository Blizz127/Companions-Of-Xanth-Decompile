extern int __near mn222E;
extern int __near mn0256;
extern int __near mn2230;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_91237(void)
{
    _asm {
        mov word ptr mn222E,0x2
        cmp word ptr mn0256,0x40
        jz short $+7
        mov ax,0x70
        jmp short $+5
L12:
        mov ax,0x71
L15:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        inc word ptr mn2230
        mov ax,0x2351
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x1
        push ax
        mov cx,0x2a
        push cx
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        retf
    }
}
