extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_63403(void)
{
    _asm {
        push word ptr mn6A04
        mov ax,0x11
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x27
        mov dx,0xf012
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        cmp word ptr mn6A02,0x0
        jz short $+33
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e05
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
L48:
        mov ax,0x2e
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x1
        retf
    }
}
