extern int __near mn0256;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_65135(void)
{
    _asm {
        mov ax,0x15
        push ax
        push word ptr mn0256
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x1e20
        jmp short $+6
        nop
L1A:
        mov ax,0x1e25
L1D:
        push ds
        push ax
        mov ax,0x1e2a
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x54
        push ax
        call far ptr helper_1
        add sp,0x8
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x4c
        mov dx,0xf012
        push dx
        push ax
        call far ptr helper_2
        add sp,0x14
        mov ax,0x1
        retf
    }
}
