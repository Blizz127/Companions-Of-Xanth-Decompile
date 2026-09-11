extern int __near mn6A06;
extern int __near mn0256;
extern int __near mn6A04;
extern int __near mn02A6;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_126946(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+97
        jmp L19B
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0xf
        jz short $+5
        jmp L19B
L1F:
        mov ax,mn0256
        sub ax,0x80
        jz short $+30
        sub ax,0xc
        jz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x22
        jmp short $+24
        nop
L43:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x21
L58:
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
L65:
        mov ax,0x1
        jmp L19D
L6B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L175
L76:
        jna short $+5
        jmp L19B
L7B:
        sub al,0x13
        jz short $+26
        sub al,0x11
        jnz short $+5
        jmp L12F
L86:
        sub al,0x1b
        jnz short $+5
        jmp L15D
L8D:
        sub al,0x5
        jnz short $+5
        jmp L16F
L94:
        jmp L19B
L97:
        mov ax,0x14
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,mn02A6
        or ax,ax
        jz short $+11
        dec ax
        jz short $+14
        dec ax
        jz short $+17
        jmp short $+31
        nop
LB7:
        mov ax,0x15
        jmp short $+12
        nop
LBD:
        mov ax,0x2722
        push ds
        jmp short $+9
LC3:
        mov ax,0x16
LC6:
        mov dx,0xf00e
        push dx
LCA:
        push ax
        call far ptr helper_1
        add sp,0x4
LD3:
        mov ax,0x17
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        cmp word ptr mn02A6,0x2
        jl short $+5
        jmp L65
LED:
        mov ax,0x18
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,mn02A6
        or ax,ax
        jz short $+7
        dec ax
        jz short $+10
        jmp short $+24
L109:
        mov ax,0x2731
        push ds
        jmp short $+9
L10F:
        mov ax,0x19
        mov dx,0xf00e
        push dx
L116:
        push ax
        call far ptr helper_1
        add sp,0x4
L11F:
        mov ax,0x2e
        push ax
        call far ptr helper_2
        add sp,0x2
        jmp L65
        nop
L12F:
        mov ax,0x273e
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
        cmp word ptr mn02A6,0x2
        jnl short $+8
        mov ax,0x1a
        jmp short $+6
        nop
L149:
        mov ax,0x1b
L14C:
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L65
        nop
L15D:
        cmp word ptr mn02A6,0x2
        jnl short $+7
        mov ax,0x1d
        jmp short $-27
L169:
        mov ax,0x1e
        jmp short $-32
        nop
L16F:
        mov ax,0x1c
        jmp short $-38
        nop
L175:
        cmp word ptr mn02A6,0x2
        jnz short $+27
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x1f
        jmp L58
        nop
L195:
        mov ax,0x20
        jmp short $-76
        nop
L19B:
        xor ax,ax
L19D:
    }
}
