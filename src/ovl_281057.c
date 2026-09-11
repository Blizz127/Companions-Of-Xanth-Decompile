extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn0256;
extern char __near mb0359;
extern char __near mb367C;
extern char __near mb0362;
extern int __near mn6A02;
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
int far ovl_281057(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L1CD
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1C7
L16:
        jna short $+5
        jmp L1CD
L1B:
        sub al,0x8
        jz short $+20
        sub al,0xb
        jz short $+38
        sub al,0x19
        jz short $+80
        sub al,0xc
        jnz short $+5
        jmp L131
L2E:
        jmp L1CD
L31:
        mov ax,0x44
L34:
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_0
L3E:
        mov sp,bp
L40:
        mov ax,0x1
        jmp L1CF
        nop
L47:
        mov ax,0x3d
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+8
        mov ax,0x3e
        jmp short $-56
        nop
L6F:
        mov ax,0x3f
        jmp short $-62
        nop
L75:
        cmp word ptr mn0256,0x169
        jz short $+68
        mov ax,0x42
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1388
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x5a03
        push ax
        mov ax,0x15
        push ax
        push word ptr mn0256
        call far ptr helper_3
        add sp,0x4
        cmp ax,0x1
        sbb ax,ax
        and ax,0x4
        add ax,0x185
        push ax
        call far ptr helper_4
        jmp L3E
LBF:
        mov ax,0x43
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x1
        push ax
        push ax
        mov ax,0xd
        push ax
        call far ptr helper_5
        add sp,0x6
        call far ptr helper_6
        mov ax,0x36bb
        push ds
        push ax
        call far ptr helper_7
        add sp,0x4
        mov ax,0x2710
        push ax
        call far ptr helper_2
        add sp,0x2
        call far ptr helper_8
        xor ax,ax
        push ax
        push ax
        mov cx,0x168
        push cx
        call far ptr helper_9
        add sp,0x6
        mov byte ptr mb0359,0x1
        mov byte ptr mb367C,0x0
        call far ptr helper_10
        or ax,ax
        jnz short $+5
        jmp L40
L129:
        mov byte ptr mb0362,0x1
        jmp L40
L131:
        cmp word ptr mn6A02,0x166
        jnz short $+60
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_11
        add sp,0x4
        push dx
        push ax
        mov ax,0x40
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x6
        jmp L40
        nop
L173:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_11
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
        push ax
        push word ptr mn6A02
        call far ptr helper_3
        add sp,0x4
        cmp ax,0x1
        sbb ax,ax
        and ax,0x6
        add ax,0x69
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_11
        add sp,0x4
        push dx
        push ax
        mov ax,0x41
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_0
        add sp,0xe
        jmp L40
        nop
L1C7:
        mov ax,0x45
        jmp L34
L1CD:
        xor ax,ax
L1CF:
    }
}
