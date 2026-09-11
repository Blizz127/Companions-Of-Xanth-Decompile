extern int __near mn69E8;
extern int __near mn0056;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_42720(void)
{
    _asm {
        mov ax,mn69E8
        dec ax
        dec ax
        jz short $+13
        dec ax
        jz short $+48
        dec ax
        jz short $+53
        dec ax
        jz short $+76
        jmp short $+79
L12:
        xor ax,ax
        push ax
        xor cx,cx
        push cx
        push ax
        push ax
        mov ax,0x50
        push ax
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0xc
        mov ax,0x1f4
        push ax
        call far ptr helper_1
        add sp,0x2
        jmp short $+41
L38:
        call far ptr helper_2
        jmp short $+34
        nop
L40:
        cmp word ptr mn0056,0x1
        sbb ax,ax
        neg ax
        push ax
        call far ptr helper_3
        add sp,0x2
        call far ptr helper_4
        jmp short $+8
        nop
L5A:
        call far ptr helper_5
L5F:
        call far ptr helper_6
        retf
    }
}
