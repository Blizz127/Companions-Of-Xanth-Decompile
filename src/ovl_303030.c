extern char __near mb6E5C;
extern int __near mn0056;
extern int __near mn0058;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
void far helper_9(void);
void far helper_10(void);
int far ovl_303030(int a)
{
    _asm {
        mov ax,[bp+0x6]
        cmp ax,0x16
        jnz short $+5
        jmp L107
L0B:
        jna short $+5
        jmp L11D
L10:
        sub al,0x8
        jnl short $+5
        jmp L11D
L17:
        sub al,0x3
        jng short $+10
        sub al,0x3
        jz short $+24
        jmp L11D
        nop
L23:
        mov ax,0x24
        mov dx,0xf047
        push dx
        push ax
        call far ptr helper_0
L30:
        mov sp,bp
        jmp L11D
L35:
        mov ax,0x19c
        push ax
        mov ax,0x1a7
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jnz short $+5
        jmp L11D
L4B:
        mov ax,0x1
        push ax
        mov ax,0x199
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jnz short $+35
        cmp byte ptr mb6E5C,0xa
        jnz short $+28
        mov ax,0xbb8
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x5a01
        push ax
        mov ax,0x2db
        push ax
        call far ptr helper_3
        mov sp,bp
L7F:
        cmp word ptr mn0056,0x1
        jz short $+85
        cmp word ptr mn0058,0x0
        jnz short $+78
        mov ax,0x7d0
        push ax
        call far ptr helper_2
        mov sp,bp
        xor al,al
        push ax
        mov ax,0x16
        push ax
        mov ax,0x118b
        push ax
        call far ptr helper_4
        mov sp,bp
        call far ptr helper_5
        mov ax,0x22
        mov dx,0xf047
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        push ax
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_6
        mov sp,bp
        mov ax,0x1770
        push ax
        call far ptr helper_2
        mov sp,bp
LD9:
        xor ax,ax
        push ax
        mov ax,0x1a4
        push ax
        mov ax,0x1a7
        push ax
        call far ptr helper_7
        mov sp,bp
        mov ax,0x23
        mov dx,0xf047
        push dx
        push ax
        call far ptr helper_8
        mov sp,bp
        mov ax,0xa
        push ax
        call far ptr helper_9
        jmp L30
        nop
L107:
        mov ax,0x6
        push ax
        mov ax,0x3c
        mov cx,0x3352
        push cx
        push ax
        call far ptr helper_10
        mov sp,bp
        jmp short $+5
        nop
L11D:
        xor ax,ax
L11F:
    }
}
