extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_122850(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+101
        jmp L25B
L0F:
        mov ax,mn6A06
        sub ax,0x48
        jz short $+5
        jmp L25B
L1A:
        cmp word ptr mn6A04,0x91
        jz short $+5
        jmp L25B
L25:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x42
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L69:
        mov ax,0x1
        jmp L25D
L6F:
        mov ax,mn6A06
        cmp ax,0x4e
        jnz short $+5
        jmp L1E5
L7A:
        jna short $+5
        jmp L25B
L7F:
        cmp al,0x2c
        jz short $+40
        ja short $+14
        sub al,0x8
        jz short $+34
        sub al,0xb
        jz short $+52
        jmp L25B
        nop
L91:
        sub al,0x44
        jnz short $+5
        jmp L12B
L98:
        dec al
        jnz short $+5
        jmp L179
L9F:
        sub al,0x2
        jnz short $+5
        jmp L1B1
LA6:
        jmp L25B
LA9:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x3d
        jmp short $+93
LBF:
        mov ax,0x72
        push ax
        mov ax,0x73
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x26a8
        jmp short $+6
        nop
LD9:
        mov ax,0x26ac
LDC:
        push ds
        push ax
        mov ax,0x38
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x105
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L69
L105:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x39
L11A:
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L69
        nop
L12B:
        mov ax,0x105
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+40
        cmp word ptr mn0256,0x105
        jnz short $+8
        mov ax,0x3a
        jmp short $+30
        nop
L14D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3b
        jmp short $-72
        nop
L165:
        mov ax,0x3c
L168:
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L69
        nop
L179:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x11
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3e
L1A0:
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp L69
        nop
L1B1:
        cmp word ptr mn6A02,0x106
        jnz short $+5
        jmp L25B
L1BC:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3f
        jmp short $-67
L1E5:
        mov ax,0x105
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x40
        jmp L168
L1FF:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x41
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x6
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov dx,0x92
        push dx
        call far ptr helper_3
        add sp,0x6
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x91
        push ax
        call far ptr helper_3
        add sp,0x6
        jmp L69
        nop
L25B:
        xor ax,ax
L25D:
    }
}
