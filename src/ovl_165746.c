extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern int __near mn02A8;
extern char __near mb0320;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_165746(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp L219
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L219
L1A:
        push word ptr mn6A02
        mov ax,0x22
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
        mov ax,0xf
L40:
        mov dx,0xf01b
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp L21B
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L201
L5E:
        jna short $+5
        jmp L219
L63:
        cmp al,0x38
        jnz short $+5
        jmp L1BB
L6A:
        ja short $+17
        sub al,0xe
        jz short $+31
        sub al,0x5
        jnz short $+5
        jmp L1B5
L77:
        jmp L219
        nop
L7B:
        sub al,0x42
        jnz short $+5
        jmp L1C1
L82:
        sub al,0x2
        jnz short $+5
        jmp L1FB
L89:
        jmp L219
        nop
L8D:
        mov ax,0x7
        mov dx,0xf01b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x13
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+76
        mov ax,0x2c0d
        push ds
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x13
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x1388
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x5a04
        push ax
        mov ax,0x303
        push ax
        call far ptr helper_5
        mov sp,bp
        mov ax,0x8
        mov dx,0xf01b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov word ptr mn02A8,0x9
        jmp L1A8
        nop
LF5:
        mov ax,0x14
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+77
        mov ax,0x9
        mov dx,0xf01b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x14
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x1388
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x5a04
        push ax
        mov ax,0x305
        push ax
        call far ptr helper_5
        mov sp,bp
        mov ax,0xa
        mov dx,0xf01b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov word ptr mn02A8,0xa
        jmp short $+91
L14F:
        mov ax,0xc7
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_6
        mov sp,bp
        or ax,ax
        jz short $+51
        mov ax,0xb
        mov dx,0xf01b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1388
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x5a03
        push ax
        mov ax,0x147
        push ax
        call far ptr helper_5
        mov sp,bp
        mov word ptr mn02A8,0xc
        jmp short $+23
L193:
        mov ax,0xc
        mov dx,0xf01b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov word ptr mn02A8,0xd
L1A8:
        mov ax,0x1388
        push ax
        call far ptr helper_4
        mov sp,bp
        jmp short $+53
L1B5:
        mov ax,0x3
        jmp L40
L1BB:
        mov ax,0x4
        jmp L40
L1C1:
        cmp byte ptr mb0320,0x0
        jz short $+47
        mov ax,0xd
        mov dx,0xf01b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1388
        push ax
        call far ptr helper_4
        mov sp,bp
        mov word ptr mn02A8,0x18
L1E8:
        mov ax,0x5a
        push ax
        call far ptr helper_7
        jmp L4A
        nop
L1F5:
        mov ax,0xe
        jmp L40
L1FB:
        mov ax,0x5
        jmp L40
L201:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x6
        jmp L40
        nop
L219:
        xor ax,ax
L21B:
    }
}
