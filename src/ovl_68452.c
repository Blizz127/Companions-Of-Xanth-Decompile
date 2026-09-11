extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb032D;
extern char __near mb033B;
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
void far helper_13(void);
void far helper_14(void);
int far ovl_68452(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+49
        jmp L2D9
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L2D9
L1A:
        cmp word ptr mn6A04,0x104
        jz short $+5
        jmp L2D9
L25:
        push word ptr mn6A04
        push word ptr mn6A02
        mov ax,0x3c
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp L2DB
L3B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L2BB
L46:
        jna short $+5
        jmp L2D9
L4B:
        cmp al,0x13
        jnz short $+5
        jmp L11F
L52:
        ja short $+13
        sub al,0x8
        jz short $+33
        sub al,0x3
        jz short $+29
        jmp L2D9
L5F:
        sub al,0x16
        jnz short $+5
        jmp L18D
L66:
        sub al,0x16
        jnz short $+5
        jmp L18D
L6D:
        sub al,0x10
        jnz short $+5
        jmp L1D7
L74:
        jmp L2D9
L77:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+111
        mov ax,0xd4
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+24
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        mov sp,bp
        push dx
        push ax
        mov ax,0x19
        jmp short $+91
LB3:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x1a
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_4
        add sp,0x8
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        mov ax,0x10d
LE8:
        push ax
        push word ptr mn6A04
        call far ptr helper_6
LF2:
        add sp,0x4
        jmp short $+36
LF7:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x1b
L10C:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_4
        add sp,0x8
L119:
        mov ax,0x1
        jmp L2DB
L11F:
        cmp byte ptr mb032D,0x0
        jnz short $+7
        mov ax,0x17
        jmp short $+22
L12B:
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x2
        cmp ax,0x10d
        jnz short $+17
        mov ax,0x18
L13F:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_4
        jmp short $-87
L14B:
        mov ax,0x95f
        push ax
        call far ptr helper_8
        add sp,0x2
        call far ptr helper_9
        xor ax,ax
        push ax
        call far ptr helper_10
        add sp,0x2
        call far ptr helper_11
        cmp byte ptr mb033B,0x0
        jnz short $-88
        mov byte ptr mb033B,0x1
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_12
        add sp,0x6
        jmp short $-114
L18D:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+50
        mov ax,0x1c
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_13
        add sp,0x4
        cmp byte ptr mb032D,0x1
        sbb ax,ax
        and al,0xdc
        add ax,0x150
        jmp LE8
        nop
L1D1:
        mov ax,0x1d
        jmp L13F
L1D7:
        cmp word ptr mn6A02,0x104
        jz short $+44
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x1f
        jmp short $+76
        nop
L209:
        cmp byte ptr mb032D,0x0
        jz short $+9
        mov ax,0x20
        jmp L13F
        nop
L217:
        mov ax,0xd4
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+58
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x21
L252:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_4
        add sp,0xc
        jmp L119
        nop
L263:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x22
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_4
        add sp,0x8
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_12
        add sp,0x6
        mov byte ptr mb032D,0x1
        mov ax,0x150
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        mov ax,0x1e76
        push ds
        push ax
        call far ptr helper_14
        jmp LF2
        nop
L2BB:
        mov ax,0x1e73
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_3
        add sp,0x8
        push dx
        push ax
        mov ax,0x1e
        jmp L10C
        nop
L2D9:
        xor ax,ax
L2DB:
    }
}
