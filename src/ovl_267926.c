extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb0358;
extern char __near mb0357;
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
void far helper_11(void);
int far ovl_267926(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L15B
L0F:
        jmp L267
        nop
L13:
        mov ax,mn6A06
        dec ax
        dec ax
        jz short $+10
        sub ax,0x36
        jz short $+5
        jmp L267
L22:
        cmp word ptr mn6A04,0x156
        jz short $+5
        jmp LF7
L2D:
        mov ax,0xa
        push ax
        push word ptr mn6A02
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+37
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x2e
L54:
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_2
L5E:
        mov sp,bp
        jmp L155
L63:
        cmp byte ptr mb0358,0x0
        jnz short $+7
        mov ax,0x2f
        jmp short $-25
L6F:
        mov ax,0x30
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov cx,0xc
        push cx
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        mov sp,bp
        mov ax,0xa
        push ax
        push word ptr mn6A02
        call far ptr helper_5
        mov sp,bp
        call far ptr helper_6
        mov ax,0xb
        push ax
        call far ptr helper_7
        mov sp,bp
        mov ax,0x1770
        push ax
        call far ptr helper_8
        mov sp,bp
        mov ax,0x5a15
        push ax
        mov ax,0x3e6
        push ax
        call far ptr helper_9
        mov sp,bp
        xor ax,ax
        mov mb0358,al
        push ax
        push ax
        mov ax,0x9
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x20
        push ax
        call far ptr helper_10
        jmp L5E
        nop
LF7:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_11
        mov sp,bp
        or ax,ax
        jnz short $+25
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x31
        jmp L54
L121:
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
        mov ax,0x32
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
L155:
        mov ax,0x1
        jmp L269
L15B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L261
L166:
        jna short $+5
        jmp L267
L16B:
        sub al,0x13
        jz short $+24
        sub al,0x24
        jz short $+120
        dec al
        jnz short $+5
        jmp L25B
L17A:
        sub al,0xc
        jnz short $+5
        jmp L25B
L181:
        jmp L267
        nop
L185:
        mov ax,0x24
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+44
        mov ax,0x25
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x14f
        push ax
        mov ax,0x157
        push ax
        call far ptr helper_11
        add sp,0x4
        or ax,ax
        jz short $+24
        mov ax,0x26
        jmp short $+6
        nop
L1D3:
        mov ax,0x27
L1D6:
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
L1E3:
        mov ax,0x28
        jmp short $+39
        nop
L1E9:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+8
        mov ax,0x2b
        jmp short $+13
        nop
L203:
        cmp byte ptr mb0357,0x0
        jz short $+21
        mov ax,0x2c
L20D:
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp L155
L21D:
        mov ax,0x2d
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov cx,0xa
        push cx
        call far ptr helper_3
        add sp,0x6
        xor ax,ax
        push ax
        mov ax,0x14f
        push ax
        mov ax,0x157
        push ax
        call far ptr helper_4
        add sp,0x6
        mov byte ptr mb0357,0x1
        jmp L155
L25B:
        mov ax,0x29
        jmp short $-81
        nop
L261:
        mov ax,0x2a
        jmp short $-87
        nop
L267:
        xor ax,ax
L269:
    }
}
