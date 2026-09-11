extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_61797(void)
{
    _asm {
        mov ax,0x32
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+8
        mov ax,0x1dec
        jmp short $+6
        nop
L16:
        mov ax,0x1df1
L19:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1
        mov dx,0xf012
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        mov ax,0x1
        retf
    }
}
