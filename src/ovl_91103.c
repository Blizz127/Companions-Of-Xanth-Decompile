extern int __near mn222E;
extern int __near mn0256;
extern int __near mn2230;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_91103(void)
{
    _asm {
        mov word ptr mn222E,0x1
        cmp word ptr mn0256,0x40
        jz short $+7
        mov ax,0x6e
        jmp short $+5
L12:
        mov ax,0x6f
L15:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        inc word ptr mn2230
        cmp word ptr mn2230,0x6
        jnc short $+33
        mov ax,0x1
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x2e
        push ax
        call far ptr helper_2
        add sp,0x2
        jmp short $+44
        nop
L4C:
        mov word ptr mn2230,0x0
        mov word ptr mn222E,0x0
        mov ax,0xc
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x2339
        push ds
        push ax
        call far ptr helper_0
        add sp,0x4
L75:
        mov ax,0x2348
        push ds
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0x1
        retf
    }
}
