extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_90723(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L173
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L16D
L16:
        jna short $+5
        jmp L173
L1B:
        cmp al,0x2c
        jz short $+34
        ja short $+14
        sub al,0x8
        jz short $+28
        sub al,0xb
        jz short $+62
        jmp L173
        nop
L2D:
        sub al,0x38
        jz short $+76
        sub al,0x7
        jz short $+126
        sub al,0x5
        jnz short $+5
        jmp LC9
L3C:
        jmp L173
L3F:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x69
L53:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L5F:
        mov ax,0x1
        jmp L175
L65:
        push word ptr mn6A04
        mov ax,0x21
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x67
        jmp short $-38
L7B:
        push word ptr mn6A02
        mov ax,0x22
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
        mov ax,0x66
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp short $-80
LB1:
        push word ptr mn6A04
        mov ax,0x23
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x6d
        jmp short $-115
        nop
LC9:
        mov ax,0x40
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+38
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x6a
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $+74
L101:
        mov ax,0x145
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+70
        mov ax,0x144
        push ax
        mov ax,0x22
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
        mov ax,0x6b
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
L149:
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x2
        jmp L5F
        nop
L159:
        mov ax,0x6c
L15C:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L5F
        nop
L16D:
        mov ax,0x68
        jmp short $-20
        nop
L173:
        xor ax,ax
L175:
    }
}
