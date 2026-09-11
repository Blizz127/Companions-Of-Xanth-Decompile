extern int __near mn02B6;
extern char __near mb1D00;
extern char __near mb032A;
extern int __near mn02B8;
extern char __near mb2BE0;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_166292(void)
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
        inc word ptr mn02B6
        mov ax,mn02B6
        dec ax
        jz short $+14
        dec ax
        jz short $+51
        dec ax
        jz short $+58
        dec ax
        jz short $+65
        jmp LC7
L2E:
        mov byte ptr mb1D00,0x0
        mov ax,0x5a04
        push ax
        mov ax,0x2e8
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x5a03
        push ax
        mov ax,0x17e
L4A:
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $+116
        nop
L56:
        mov ax,0x5a04
        push ax
        mov ax,0x2f0
        jmp short $-19
        nop
L60:
        mov ax,0x5a04
        push ax
        mov ax,0x2f9
        jmp short $-29
        nop
L6A:
        mov ax,0x5a04
        push ax
        mov ax,0x2fb
        push ax
        call far ptr helper_2
        add sp,0x4
        xor ax,ax
        push ax
        mov cx,0x12
        push cx
        mov cx,0x8026
        push cx
        call far ptr helper_3
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        mov cx,0xa
        push cx
        call far ptr helper_4
        add sp,0x6
        mov byte ptr mb032A,0x1
        inc word ptr mn02B8
        mov byte ptr mb2BE0,0x0
        mov ax,0x40
        push ax
        call far ptr helper_5
        add sp,0x2
        xor ax,ax
        push ax
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_6
        add sp,0x6
LC7:
        cmp word ptr mn02B6,0x4
        jnl short $+18
        mov ax,0x3
        push ax
        mov ax,0x13
        push ax
        call far ptr helper_7
        add sp,0x4
LDE:
        mov ax,0x1
        retf
    }
}
