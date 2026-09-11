extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern int __near mn0256;
extern char __near mb38EE;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far ovl_298455(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+103
        jmp L217
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L217
L1A:
        cmp word ptr mn6A04,0xce
        jnz short $+25
        push word ptr mn6A04
        push word ptr mn6A02
        mov ax,0x4
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp L219
        nop
L39:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x15
L5F:
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
L6B:
        mov ax,0x1
        jmp L219
L71:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L211
L7C:
        jna short $+5
        jmp L217
L81:
        cmp al,0x13
        jnz short $+5
        jmp L1E5
L88:
        ja short $+17
        sub al,0x4
        jz short $+31
        sub al,0x4
        jnz short $+5
        jmp L1D5
L95:
        jmp L217
        nop
L99:
        sub al,0x2c
        jnz short $+5
        jmp L1D5
LA0:
        sub al,0x18
        jnz short $+5
        jmp L1F9
LA7:
        jmp L217
        nop
LAB:
        mov ax,0x1
        push ax
        push word ptr mn6A02
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jnz short $+61
        push word ptr mn6A02
        mov ax,0x6
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
        jmp L5F
LF9:
        cmp word ptr mn6A02,0xce
        jz short $+44
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x12
        jmp L5F
        nop
L12B:
        mov ax,0xe
        push ax
        mov ax,0xce
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+40
        mov ax,0xce
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x13
L154:
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp L6B
        nop
L165:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov cx,0xa
        push cx
        call far ptr helper_5
        add sp,0x6
        mov ax,0xa
        push ax
        mov ax,0x195
        push ax
        call far ptr helper_6
        add sp,0x4
        xor ax,ax
        push ax
        push word ptr mn0256
        push word ptr mn6A02
        call far ptr helper_7
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x6
        mov byte ptr mb38EE,0x0
        jmp L6B
L1D5:
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x2
        jmp L6B
        nop
L1E5:
        mov ax,0xe
L1E8:
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp L6B
        nop
L1F9:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xf
        jmp L154
L211:
        mov ax,0x10
        jmp short $-44
        nop
L217:
        xor ax,ax
L219:
    }
}
