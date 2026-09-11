extern int __near mn6A06;
extern int __near mn6A04;
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
int far ovl_67478(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LF1
L0F:
        jmp L2C1
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L2C1
L1E:
        mov ax,0x14
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+56
        push word ptr mn6A02
        mov ax,0x1
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
        mov ax,0xe
L57:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        jmp LEB
        nop
L67:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+43
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xf
        jmp short $-73
        nop
LA3:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x10
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x6
LEB:
        mov ax,0x1
        jmp L2C3
LF1:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L2A9
LFC:
        jna short $+5
        jmp L2C1
L101:
        sub al,0x8
        jz short $+26
        sub al,0xb
        jnz short $+5
        jmp L19B
L10C:
        sub al,0x19
        jnz short $+5
        jmp L1E9
L113:
        sub al,0xe
        jnz short $+5
        jmp L19B
L11A:
        jmp L2C1
L11D:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+38
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
L146:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $-104
L155:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xc
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        mov ax,0x2c
L18A:
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        jmp LEB
        nop
L19B:
        mov ax,0x57
        push ax
        call far ptr helper_7
        add sp,0x2
        or ax,ax
        jnz short $+10
        mov ax,0x9
        mov dx,0xf015
        jmp short $+5
L1B3:
        xor ax,ax
        cwd
L1B6:
        push dx
        push ax
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x1e52
        jmp short $+5
L1D1:
        mov ax,0x1e57
L1D4:
        push ds
        push ax
        mov ax,0x8
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        jmp LEB
L1E9:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+32
        mov ax,0x1e5e
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_1
        add sp,0x8
        push dx
        push ax
        mov ax,0x3
        jmp L146
        nop
L21B:
        mov ax,0x57
        push ax
        call far ptr helper_7
        add sp,0x2
        or ax,ax
        jnz short $+74
        mov ax,0x56
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xa
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0x57
        push ax
        call far ptr helper_8
        add sp,0x2
        mov ax,0x55
        push ax
        call far ptr helper_8
        add sp,0x2
        mov ax,0x54
        push ax
        call far ptr helper_8
        add sp,0x2
        jmp short $+33
L273:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e62
        push ds
        push ax
        call far ptr helper_2
        add sp,0x8
L292:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x4
        mov ax,0x8
        jmp L18A
        nop
L2A9:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xd
        jmp L146
L2C1:
        xor ax,ax
L2C3:
    }
}
