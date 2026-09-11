extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn02A6;
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
int far ovl_148888(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+37
        jmp L1B7
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L1B7
L1A:
        mov ax,0x15
L1D:
        mov dx,0xf018
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
L29:
        mov ax,0x1
        jmp L1B9
L2F:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L16D
L3A:
        jna short $+5
        jmp L1B7
L3F:
        sub al,0x13
        jz short $+20
        sub al,0x25
        jz short $+116
        sub al,0x2
        jz short $+12
        sub al,0xa
        jnz short $+5
        jmp L11F
L52:
        jmp L1B7
L55:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jnz short $+49
        cmp word ptr mn6A06,0x3a
        jnz short $+10
        mov ax,0x10
        mov dx,0xf018
        jmp short $+3
L77:
        cwd
L78:
        push dx
        push ax
        mov ax,0x2a16
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x53
        push ax
        call far ptr helper_2
        add sp,0x8
        push dx
        push ax
        mov ax,0xf
        jmp short $-119
        nop
L97:
        mov ax,0x66c
        push ax
        call far ptr helper_3
        mov sp,bp
        call far ptr helper_4
        xor ax,ax
        push ax
        call far ptr helper_5
        mov sp,bp
        call far ptr helper_6
        jmp L29
LB9:
        cmp word ptr mn02A6,0x2
        jnl short $+25
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x13
        jmp short $+116
        nop
LD7:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
        mov dx,0xf018
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x6
        jmp L29
        nop
L11F:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+40
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
L148:
        mov dx,0xf018
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp L29
        nop
L159:
        mov ax,0x64e
        push ax
        mov ax,0x353
        push ax
        call far ptr helper_8
        add sp,0x4
        jmp L29
        nop
L16D:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x12
        mov dx,0xf018
        push dx
        push ax
        call far ptr helper_0
        add sp,0x10
        jmp L29
        nop
L1B7:
        xor ax,ax
L1B9:
    }
}
