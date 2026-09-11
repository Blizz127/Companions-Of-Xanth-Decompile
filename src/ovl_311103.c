extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb39C2;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far ovl_311103(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+103
        jmp L24D
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L24D
L1A:
        cmp word ptr mn6A04,0x199
        jnz short $+25
        push word ptr mn6A04
        push word ptr mn6A02
        mov ax,0x4d
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp L24F
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
        mov ax,0x45
L5F:
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
L6B:
        mov ax,0x1
        jmp L24F
L71:
        mov ax,mn6A06
        cmp ax,0x4d
        jnz short $+5
        jmp L169
L7C:
        jna short $+5
        jmp L24D
L81:
        cmp al,0x2c
        jz short $+110
        ja short $+14
        sub al,0x8
        jz short $+28
        sub al,0xb
        jz short $+46
        jmp L24D
        nop
L93:
        sub al,0x44
        jnz short $+5
        jmp L131
L9A:
        dec al
        jnz short $+5
        jmp L163
LA1:
        jmp L24D
        nop
LA5:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x3d
        jmp short $-90
LBB:
        push word ptr mn6A04
        mov ax,0x21
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x1ba
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x39f2
        jmp short $+5
LE5:
        mov ax,0x39f4
LE8:
        push ds
        push ax
        mov ax,0x3a
        jmp L5F
        nop
LF1:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x3f
        jmp L19A
L10B:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x40
L120:
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp L6B
        nop
L131:
        mov ax,0x1ba
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x3b
        jmp short $+82
        nop
L14B:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x3c
        jmp short $-64
        nop
L163:
        mov ax,0x3e
        jmp short $+52
        nop
L169:
        mov ax,0x1b8
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x41
        jmp short $+26
        nop
L183:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+22
        mov ax,0x42
L19A:
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp L6B
        nop
L1AB:
        cmp word ptr mn6A02,0x199
        jz short $+44
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
        mov ax,0x43
        jmp L5F
L1DD:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x44
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_6
        add sp,0x6
        mov byte ptr mb39C2,0x1
        call far ptr helper_7
        mov ax,0x1ba
        push ax
        call far ptr helper_8
        add sp,0x2
        jmp L6B
L24D:
        xor ax,ax
L24F:
    }
}
