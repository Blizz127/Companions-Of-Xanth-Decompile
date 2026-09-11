extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_63699(void)
{
    _asm {
        mov ax,0xb
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2d
        jmp short $+24
        nop
L2C:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2e
L41:
        mov dx,0xf012
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0x1
        retf
    }
}
