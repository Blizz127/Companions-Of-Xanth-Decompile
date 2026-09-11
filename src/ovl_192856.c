extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn0256;
extern int __near mn6A02;
extern int __near mn02A8;
extern char __near mb0330;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_192856(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L1BF
L0F:
        jmp L2B9
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L2B9
L1E:
        cmp word ptr mn6A04,0xd9
        jz short $+5
        jmp L133
L29:
        cmp word ptr mn0256,0xfb
        jz short $+5
        jmp L133
L34:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+18
        mov ax,0x3087
        push ds
        push ax
        call far ptr helper_1
L51:
        mov sp,bp
        jmp L1B9
        nop
L57:
        push word ptr mn6A04
        mov ax,0xff
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+61
        mov ax,0x1e
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov ax,0xff
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1b58
        push ax
        call far ptr helper_3
        mov sp,bp
        mov word ptr mn02A8,0xf
        mov ax,0x5a
        push ax
        call far ptr helper_4
        jmp short $-81
        nop
LA5:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_5
        mov sp,bp
        push dx
        push ax
        mov ax,0xd9
        push ax
        mov ax,0xfe
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+11
        mov ax,0x20
        mov dx,0xf021
        jmp short $+6
        nop
LD3:
        xor ax,ax
        cwd
LD6:
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        mov ax,0x1f
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        push word ptr mn6A04
        mov ax,0xfe
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+5
        jmp L1B9
L122:
        mov ax,0x1
        push ax
        mov ax,0x1a
        push ax
        call far ptr helper_6
        jmp L51
        nop
L133:
        cmp word ptr mn0256,0xfb
        jnz short $+76
        cmp word ptr mn6A04,0xfe
        jnz short $+26
        push word ptr mn6A02
        mov ax,0xd9
        push ax
        push word ptr mn6A06
        call far ptr helper_7
        add sp,0x6
        jmp L2BB
        nop
L15B:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        mov ax,0x21
        jmp short $+42
        nop
L185:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        mov ax,0x22
L1AC:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
L1B9:
        mov ax,0x1
        jmp L2BB
L1BF:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L2A1
L1CA:
        jna short $+5
        jmp L2B9
L1CF:
        sub al,0x8
        jz short $+20
        sub al,0xb
        jz short $+52
        sub al,0x19
        jz short $+12
        sub al,0x18
        jnz short $+5
        jmp L26D
L1E2:
        jmp L2B9
L1E5:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        mov ax,0x1c
L1FA:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $-78
L209:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        mov ax,0x17
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        cmp word ptr mn0256,0xfb
        jnz short $-120
        push word ptr mn6A04
        mov ax,0xd9
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x19
        mov dx,0xf021
        jmp short $+5
L24F:
        xor ax,ax
        cwd
L252:
        push dx
        push ax
        mov ax,0x18
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov byte ptr mb0330,0x1
        jmp L1B9
        nop
L26D:
        cmp word ptr mn0256,0xfb
        jz short $+22
        mov ax,0x1a
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L1B9
        nop
L289:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        mov ax,0x1b
        jmp L1FA
L2A1:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d
        jmp L1FA
L2B9:
        xor ax,ax
L2BB:
    }
}
