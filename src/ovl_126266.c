extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern int __near mn0256;
extern char __near mb0343;
extern int __near mn02A6;
extern char __near mb26EE;
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
int far ovl_126266(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+46
        jmp L29F
        nop
L13:
        mov ax,mn6A06
        sub ax,0x33
        jz short $+10
        sub ax,0x5
        jz short $+5
        jmp L29F
L23:
        push word ptr mn6A04
        push word ptr mn6A02
        mov ax,0xd
        push ax
        call far ptr helper_0
        add sp,0x6
        jmp L2A1
        nop
L3B:
        mov ax,mn6A06
        cmp ax,0x3f
        jnz short $+5
        jmp L28B
L46:
        jna short $+5
        jmp L29F
L4B:
        sub al,0xd
        jz short $+12
        sub al,0x6
        jnz short $+5
        jmp L253
L56:
        jmp L29F
L59:
        mov ax,mn0256
        sub ax,0x8c
        jz short $+10
        sub ax,0x8
        jz short $+25
        jmp L24E
L69:
        mov ax,0x9
L6C:
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_1
L76:
        add sp,0x4
        jmp L24E
        nop
L7D:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0xa
        jmp short $-40
        nop
L97:
        cmp word ptr mn6A02,0x9b
        jz short $+56
        cmp word ptr mn6A02,0x88
        jz short $+48
        cmp word ptr mn6A02,0x89
        jz short $+40
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
LC4:
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L24E
        nop
LD5:
        call far ptr helper_4
        or ax,ax
        jnz short $+57
        push word ptr mn6A04
        mov ax,0x22
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
        mov ax,0xc
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp L24E
L115:
        cmp word ptr mn6A02,0x9b
        jnz short $+8
        mov ax,0xd
        jmp L6C
L123:
        push word ptr mn6A02
        call far ptr helper_5
        add sp,0x2
        cmp ax,0x122
        jnz short $+27
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0xe
        jmp LC4
        nop
L14D:
        push word ptr mn6A02
        call far ptr helper_5
        add sp,0x2
        cmp ax,0x146
        jnz short $+81
        cmp byte ptr mb0343,0x0
        jz short $+10
        mov ax,0x2713
        mov dx,ds
        jmp short $+6
        nop
L16D:
        xor ax,ax
        cwd
L170:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0xf
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        xor ax,ax
        push ax
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_6
        add sp,0x6
        mov byte ptr mb0343,0x0
L19D:
        mov ax,0x122
        push ax
        push word ptr mn6A02
        call far ptr helper_7
        jmp L76
L1AD:
        push word ptr mn6A02
        call far ptr helper_5
        add sp,0x2
        cmp ax,0x14a
        jnz short $+21
        mov ax,0x10
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-49
        nop
L1D1:
        mov ax,0xa
        push ax
        push word ptr mn6A02
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+107
        mov ax,0x11
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x4
        inc word ptr mn02A6
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0xf
        push ax
        call far ptr helper_9
        add sp,0x6
        mov ax,0x122
        push ax
        push word ptr mn6A02
        call far ptr helper_7
        add sp,0x4
        mov ax,0xd
        push ax
        push word ptr mn6A04
        call far ptr helper_10
        add sp,0x4
        mov ax,0x271b
        push ds
        push ax
        call far ptr helper_11
        add sp,0x4
        mov byte ptr mb26EE,0x0
L24E:
        mov ax,0x1
        jmp short $+80
L253:
        mov ax,mn0256
        sub ax,0x8c
        jz short $+10
        sub ax,0x8
        jz short $+25
        jmp short $-18
        nop
L263:
        cmp word ptr mn02A6,0x0
        jnz short $+9
        mov ax,0x5
        jmp L6C
        nop
L271:
        mov ax,0x6
        jmp L6C
L277:
        cmp word ptr mn02A6,0x0
        jnz short $+9
        mov ax,0x7
        jmp L6C
        nop
L285:
        mov ax,0x8
        jmp L6C
L28B:
        cmp word ptr mn02A6,0x1
        jnl short $+9
        mov ax,0x12
        jmp L6C
        nop
L299:
        mov ax,0x13
        jmp L6C
L29F:
        xor ax,ax
L2A1:
    }
}
