extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_319951(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LAB
L0F:
        jmp L10B
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x17
        jz short $+5
        jmp L10B
L23:
        cmp word ptr mn6A04,0x1ee
        jz short $+44
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
        jmp LF9
        nop
L55:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x21
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov cx,0xa
        push cx
        call far ptr helper_2
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov cx,0x1d4
        push cx
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov ax,0x1ee
        push ax
        call far ptr helper_3
LA3:
        mov sp,bp
        mov ax,0x1
        jmp short $+101
        nop
LAB:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+84
        ja short $+88
        cmp al,0x13
        jz short $+40
        ja short $+12
        sub al,0x3
        jz short $+22
        sub al,0x5
        jz short $+24
        jmp short $+72
LC5:
        sub al,0x1d
        jz short $+12
        sub al,0xf
        jz short $+26
        sub al,0x18
        jz short $+22
        jmp short $+58
LD3:
        mov ax,0x20
        jmp short $+35
        nop
LD9:
        mov ax,0x1e
        jmp short $+29
        nop
LDF:
        mov ax,0x1c
        jmp short $+23
        nop
LE5:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1d
LF9:
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_1
        jmp short $-96
L105:
        mov ax,0x1f
        jmp short $-15
        nop
L10B:
        xor ax,ax
L10D:
    }
}
