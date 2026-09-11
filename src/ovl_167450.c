extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn0256;
extern char __near mb032A;
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
int far ovl_167450(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L1F1
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1EB
L16:
        jna short $+5
        jmp L1F1
L1B:
        cmp al,0x2c
        jnz short $+5
        jmp L11B
L22:
        ja short $+21
        sub al,0x8
        jz short $+39
        sub al,0xb
        jz short $+129
        sub al,0xe
        jnz short $+5
        jmp LCF
L33:
        jmp L1F1
        nop
L37:
        sub al,0x36
        jnz short $+5
        jmp L11B
L3E:
        dec al
        jz short $+13
        sub al,0xd
        jnz short $+5
        jmp L1D1
L49:
        jmp L1F1
        nop
L4D:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+9
        mov ax,0x9
        jmp L1C4
        nop
L67:
        cmp word ptr mn0256,0xc9
        jz short $+8
        mov ax,0xa
        jmp L1C4
L75:
        mov ax,0xb
        mov dx,0xf01c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        mov ax,0x2c
        push ax
        push word ptr mn6A04
        call far ptr helper_3
LA2:
        add sp,0x4
LA5:
        mov ax,0x1
        jmp L1F3
LAB:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x2c41
        jmp short $+6
        nop
LC5:
        mov ax,0x2c46
LC8:
        push ds
        push ax
        mov ax,0x3
        jmp short $+31
LCF:
        cmp word ptr mn0256,0xc9
        jz short $+38
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_4
        add sp,0x4
        push dx
        push ax
        mov ax,0xd
LEC:
        mov dx,0xf01c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $-84
LFB:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0xe
        jmp L1C4
L115:
        mov ax,0xf
        jmp L1C4
L11B:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x5
        jmp L1C4
L135:
        cmp word ptr mn0256,0xc9
        jz short $+10
        mov ax,0x6
        jmp L1C4
        nop
        nop
L145:
        cmp byte ptr mb032A,0x0
        jz short $+119
        mov ax,0x7
        mov dx,0xf01c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x2c53
        push ds
        push ax
        call far ptr helper_5
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        mov ax,0x8
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        call far ptr helper_7
        call far ptr helper_8
        xor al,al
        push ax
        mov cx,0x1d
        push cx
        mov dx,0x883
        push dx
        call far ptr helper_9
        add sp,0x6
        xor al,al
        push ax
        mov ax,0x1d
        push ax
        mov ax,0x883
        push ax
        call far ptr helper_9
        add sp,0x6
        call far ptr helper_10
        jmp LA5
L1C1:
        mov ax,0x8
L1C4:
        mov dx,0xf01c
        push dx
        push ax
        call far ptr helper_1
        jmp LA2
L1D1:
        cmp word ptr mn0256,0xc9
        jnz short $+8
        mov ax,0x2c4d
        jmp short $+6
        nop
L1DF:
        mov ax,0x2c50
L1E2:
        push ds
        push ax
        mov ax,0x4
        jmp LEC
        nop
L1EB:
        mov ax,0xc
        jmp short $-42
        nop
L1F1:
        xor ax,ax
L1F3:
    }
}
