extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb030C;
extern char __near mb0305;
extern char __near mb0300;
extern char __near mb0302;
extern int __near mn02A6;
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
void far helper_12(void);
int far ovl_159521(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LFB
L0F:
        jmp L25B
        nop
L13:
        mov ax,mn6A06
        sub ax,0x19
        jz short $+5
        jmp L25B
L1E:
        mov ax,mn6A04
        cmp ax,0x8a
        jnz short $+5
        jmp LB3
L29:
        jg short $+22
        sub ax,0x73
        jz short $+45
        sub ax,0x15
        jnl short $+5
        jmp L25B
L38:
        dec ax
        jng short $+96
        jmp L25B
        nop
L3F:
        sub ax,0x8b
        jnz short $+5
        jmp LD3
L47:
        sub ax,0x8
        jnz short $+5
        jmp LD3
L4F:
        sub ax,0x8
        jnz short $+5
        jmp LE5
L57:
        jmp L25B
        nop
L5B:
        cmp byte ptr mb030C,0x0
        jz short $+35
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1c
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_1
        jmp short $+16
        nop
L83:
        mov ax,0x5a0b
        push ax
        mov ax,0x27b
        push ax
        call far ptr helper_2
L90:
        mov sp,bp
L92:
        mov ax,0x1
        jmp L25D
        nop
L99:
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        cmp ax,0x147
        jnz short $+44
        mov ax,0x5a0b
        push ax
        mov ax,0x297
        jmp short $+42
        nop
LB3:
        mov ax,0x1
        push ax
        mov ax,0x8b
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp L25B
LCA:
        mov ax,0x5a0b
        push ax
        mov ax,0x294
        jmp short $+9
LD3:
        mov ax,0x5a0b
        push ax
        mov ax,0x299
LDA:
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $-81
LE5:
        call far ptr helper_5
        or ax,ax
        jnz short $+5
        jmp L25B
LF1:
        mov ax,0x5a0b
        push ax
        mov ax,0x295
        jmp short $-30
        nop
LFB:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+41
        jmp L25B
L10B:
        cmp byte ptr mb0305,0x0
        jz short $+7
        mov ax,0x1a
        jmp short $+5
L117:
        mov ax,0x1b
L11A:
        mov dx,0xf006
        push dx
        push ax
        mov ax,0x19
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L92
L12F:
        cmp byte ptr mb0300,0x0
        jnz short $+11
        mov ax,0x5a0b
        push ax
        mov ax,0x269
        jmp short $+32
L13F:
        cmp byte ptr mb0302,0x0
        jnz short $+11
        mov ax,0x5a0b
        push ax
        mov ax,0x271
        jmp short $+16
L14F:
        cmp byte ptr mb0305,0x0
        jnz short $+27
        mov ax,0x5a0b
        push ax
        mov ax,0x275
L15D:
        push ax
        call far ptr helper_2
        add sp,0x4
        call far ptr helper_6
        jmp L92
        nop
L16F:
        cmp byte ptr mb030C,0x0
        jz short $+113
        mov ax,0x73
        push ax
        call far ptr helper_7
        add sp,0x2
        or ax,ax
        jnz short $+97
        mov ax,0x5a0b
        push ax
        mov ax,0x281
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x73
        push ax
        call far ptr helper_3
        add sp,0x2
        cmp ax,0x12d
        jz short $+5
        jmp L92
L1AA:
        mov ax,0xa
        push ax
        mov ax,0x80
        push ax
        call far ptr helper_8
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp L92
L1C1:
        mov ax,0xa
        push ax
        mov ax,0x80
        push ax
        call far ptr helper_9
        add sp,0x4
        xor ax,ax
        push ax
        push ax
        mov ax,0x9
        push ax
        call far ptr helper_10
L1DE:
        add sp,0x6
        jmp L92
        nop
L1E5:
        mov ax,0x1
        push ax
        mov ax,0x73
        push ax
        call far ptr helper_11
        add sp,0x4
        or ax,ax
        jz short $+20
        cmp byte ptr mb030C,0x0
        jnz short $+13
        mov ax,0x5a0b
        push ax
        mov ax,0x27b
        jmp LDA
        nop
L20B:
        cmp word ptr mn02A6,0x2
        jnl short $+13
        mov ax,0x5a0b
        push ax
        mov ax,0x28e
        jmp LDA
        nop
L21D:
        mov ax,0x1
        push ax
        mov ax,0x8b
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+12
        mov ax,0x5a0b
        push ax
        mov ax,0x28d
        jmp LDA
L23B:
        mov ax,0x5a0b
        push ax
        mov ax,0x293
        push ax
        call far ptr helper_2
        add sp,0x4
        xor ax,ax
        push ax
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_12
        jmp short $-122
        nop
L25B:
        xor ax,ax
L25D:
    }
}
