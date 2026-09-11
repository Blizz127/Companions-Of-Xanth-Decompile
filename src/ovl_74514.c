extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
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
int far ovl_74514(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L1DB
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1D3
L16:
        jna short $+5
        jmp L1DB
L1B:
        cmp al,0x38
        jz short $+118
        ja short $+14
        sub al,0x2
        jz short $+24
        sub al,0x11
        jz short $+78
        jmp L1DB
        nop
L2D:
        sub al,0x3a
        jz short $+70
        dec al
        jnz short $+5
        jmp L1AB
L38:
        jmp L1DB
L3B:
        cmp word ptr mn6A02,0x27
        jz short $+31
        cmp word ptr mn6A02,0x28
        jz short $+24
        mov ax,0x24
L4C:
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_0
L56:
        mov sp,bp
L58:
        mov ax,0x1
        jmp L1DD
        nop
L5F:
        push word ptr mn6A02
        push word ptr mn6A04
        mov ax,0x38
L6A:
        push ax
L6B:
        call far ptr helper_1
        mov sp,bp
        jmp L1DD
L75:
        mov ax,0x1f
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-59
L93:
        cmp word ptr mn6A02,0x28
        jnz short $+17
        mov ax,0x27
        push ax
        push word ptr mn6A04
        push word ptr mn6A06
        jmp short $-59
        nop
LA9:
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x6
        or ax,ax
        jz short $+5
        jmp L173
LC4:
        mov ax,0xb
        push ax
        push word ptr mn6A02
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L173
LDB:
        mov ax,0x1f46
        push ds
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jnz short $+63
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x2
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_7
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_7
        add sp,0x4
        push dx
        push ax
        mov ax,0x20
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
L139:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_7
        add sp,0x4
        push dx
        push ax
        mov ax,0x21
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x6
        jmp L58
        nop
L173:
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_7
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_7
        add sp,0x4
        push dx
        push ax
        mov ax,0x22
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        jmp L58
        nop
L1AB:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x23
        jmp L4C
L1C5:
        xor ax,ax
        push ax
        push word ptr mn6A04
        mov ax,0x44
        jmp L6A
        nop
L1D3:
        call far ptr helper_10
        jmp L58
L1DB:
        xor ax,ax
L1DD:
    }
}
