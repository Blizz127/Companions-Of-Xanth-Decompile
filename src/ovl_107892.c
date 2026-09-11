extern int __near mn02C6;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_107892(void)
{
    _asm {
        inc word ptr mn02C6
        mov ax,0x76
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2534
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,mn02C6
        dec ax
        jz short $+13
        dec ax
        jz short $+32
        dec ax
        jz short $+51
        dec ax
        jz short $+80
        jmp short $+126
L34:
        mov ax,0x137
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x253d
        push ds
        jmp short $+47
L4A:
        mov ax,0x138
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x35
        jmp short $+22
        nop
L60:
        mov ax,0x139
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x36
L73:
        mov dx,0xf030
        push dx
L77:
        push ax
        call far ptr helper_1
        jmp short $+48
        nop
L80:
        mov ax,0x37
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_3
        add sp,0x6
        mov ax,0x136
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_2
LAD:
        add sp,0x4
LB0:
        mov ax,0x254b
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
        cmp word ptr mn02C6,0x4
        jnl short $+20
        mov ax,0x5
        push ax
        mov ax,0x8
        push ax
        call far ptr helper_4
        add sp,0x4
        jmp short $+8
LD6:
        mov word ptr mn02C6,0x0
LDC:
        mov ax,0x1
        retf
    }
}
