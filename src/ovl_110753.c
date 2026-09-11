extern int __near mn02A0;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_110753(void)
{
    _asm {
        inc word ptr mn02A0
        mov ax,mn02A0
        dec ax
        jz short $+16
        dec ax
        jz short $+31
        dec ax
        jz short $+34
        dec ax
        jz short $+37
        dec ax
        jz short $+40
        jmp short $+92
L18:
        mov ax,0x2c
L1B:
        mov dx,0xf00a
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        jmp short $+74
L2A:
        mov ax,0x2d
        jmp short $-18
        nop
L30:
        mov ax,0x2e
        jmp short $-24
        nop
L36:
        mov ax,0x2f
        jmp short $-30
        nop
L3C:
        mov ax,0xb
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x1b58
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x5a03
        push ax
        mov ax,0x11a
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0x5a
        push ax
        call far ptr helper_4
        add sp,0x2
        jmp short $+18
L72:
        mov ax,0x1
        push ax
        mov cx,0x9
        push cx
        call far ptr helper_5
        add sp,0x4
L82:
        mov ax,0x1
        retf
    }
}
