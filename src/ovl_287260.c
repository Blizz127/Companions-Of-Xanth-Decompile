extern char __near mb1D00;
extern int __near mn0798;
extern int __near mn0290;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_287260(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x8
        jnl short $+5
        jmp L154
L0B:
        jno short $+5
        jmp L154
L10:
        sub ax,0x3
        jng short $+10
        sub ax,0x3
        jz short $+23
        jmp L154
L1D:
        mov ax,0x5
        mov dx,0xf02d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp L154
L2F:
        mov ax,0x1
        push ax
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0xfa0
        push ax
        call far ptr helper_2
        mov sp,bp
        xor ax,ax
        mov dx,0xf02d
        push dx
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x1
        mov dx,0xf02d
        push dx
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x5a03
        push ax
        mov cx,0x19f
        push cx
        call far ptr helper_4
        mov sp,bp
        mov ax,0x2
        mov dx,0xf02d
        push dx
        push ax
        call far ptr helper_3
        mov sp,bp
        mov byte ptr mb1D00,0x0
        mov ax,0x5a0d
        push ax
        mov cx,0x25a
        push cx
        call far ptr helper_4
        mov sp,bp
        mov ax,0x5a01
        push ax
        mov cx,0x2d3
        push cx
        call far ptr helper_4
        mov sp,bp
        mov ax,0x3
        mov dx,0xf02d
        push dx
        push ax
        call far ptr helper_3
        mov sp,bp
        mov byte ptr mb1D00,0x0
        mov ax,0x5a01
        push ax
        mov cx,0x2d4
        push cx
        call far ptr helper_4
        mov sp,bp
        mov byte ptr mb1D00,0x0
        mov ax,0x5a0d
        push ax
        mov cx,0x25d
        push cx
        call far ptr helper_4
        mov sp,bp
        mov byte ptr mb1D00,0x0
        mov ax,0x5a01
        push ax
        mov ax,0x2d7
        push ax
        call far ptr helper_4
        mov sp,bp
        mov byte ptr mb1D00,0x0
        mov ax,0x5a03
        push ax
        mov ax,0x1a3
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x5a0d
        push ax
        mov ax,0x25e
        push ax
        call far ptr helper_4
        mov ax,0x4
        mov sp,bp
        mov dx,0xf02d
        push dx
        push ax
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1d5
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_5
        mov ax,0x6
        mov sp,bp
        mov mn0798,ax
        mov mn0290,ax
        mov ax,0x20
        push ax
        call far ptr helper_6
        mov sp,bp
        mov ax,0x180
        push ax
        call far ptr helper_7
L154:
        xor ax,ax
    }
}
