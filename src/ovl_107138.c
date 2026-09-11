extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
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
int far ovl_107138(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L1D3
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1CD
L16:
        jna short $+5
        jmp L1D3
L1B:
        cmp al,0x13
        jnz short $+5
        jmp L18D
L22:
        ja short $+17
        sub al,0x4
        jz short $+34
        sub al,0x4
        jnz short $+5
        jmp L17B
L2F:
        jmp L1D3
        nop
L33:
        sub al,0x24
        jnz short $+5
        jmp L1B1
L3A:
        sub al,0x8
        jnz short $+5
        jmp L17B
L41:
        sub al,0x18
        jz short $+5
        jmp L1D3
L48:
        mov ax,0x75
        push ax
        mov ax,0x78
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+38
        mov ax,0x75
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x26
L6F:
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        jmp L176
        nop
L7F:
        mov ax,0x1
        push ax
        mov ax,0x75
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jnz short $+21
        cmp word ptr mn6A02,0x75
        jnz short $+8
        mov ax,0x27
        jmp short $-45
        nop
L9F:
        mov ax,0x28
        jmp short $-51
        nop
LA5:
        cmp word ptr mn6A02,0x0
        jnz short $+7
        mov ax,0x29
        jmp short $-64
LB1:
        cmp word ptr mn6A02,0x75
        jz short $+43
        push word ptr mn6A04
        mov ax,0x3
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2a
        jmp short $-111
        nop
LE1:
        mov ax,0x75
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+25
        mov ax,0x75
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x2b
        jmp L6F
L10B:
        mov ax,0x2c
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        push ax
        mov ax,0x75
        push ax
        mov cx,0x78
        push cx
        call far ptr helper_4
        add sp,0x6
        mov ax,0x118
        push ax
        mov ax,0x75
        push ax
        call far ptr helper_5
        add sp,0x4
        mov ax,0xa
        push ax
        mov ax,0x78
        push ax
        call far ptr helper_6
        add sp,0x4
        or ax,ax
        jnz short $+37
        mov ax,0xa
        push ax
        mov ax,0x78
        push ax
        call far ptr helper_7
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x8
        push ax
        call far ptr helper_8
        add sp,0x6
L176:
        mov ax,0x1
        jmp short $+92
L17B:
        mov ax,0x2e
L17E:
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_2
L188:
        add sp,0x4
        jmp short $-21
L18D:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x25
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $-57
L1B1:
        mov ax,0x2f
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x2520
        push ds
        push ax
        call far ptr helper_9
        jmp short $-67
L1CD:
        mov ax,0x2d
        jmp short $-82
        nop
L1D3:
        xor ax,ax
L1D5:
    }
}
