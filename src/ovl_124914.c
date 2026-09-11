extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_124914(void)
{
    _asm {
        mov ax,0xb
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0x1388
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x5a03
        push ax
        cmp word ptr mn0256,0x8c
        jnz short $+8
        mov ax,0x192
        jmp short $+6
        nop
L2A:
        mov ax,0x196
L2D:
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        retf
    }
}
