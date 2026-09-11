extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_99662(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L167
L0E:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L14F
L19:
        jna short $+5
        jmp L167
L1E:
        cmp al,0x2c
        jz short $+27
        ja short $+13
        sub al,0x8
        jz short $+21
        sub al,0xb
        jz short $+65
        jmp L167
L2F:
        sub al,0x2e
        jz short $+94
        sub al,0x16
        jz short $+90
        jmp L167
        nop
L3B:
        cmp word ptr mn6A06,0x8
        jnz short $+9
        mov ax,0x2405
        mov dx,ds
        jmp short $+5
L49:
        xor ax,ax
        cwd
L4C:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x11
L57:
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
L64:
        mov ax,0x1
        jmp L169
        nop
L6B:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x23f0
        jmp short $+6
        nop
L85:
        mov ax,0x23f7
L88:
        push ds
        push ax
        mov ax,0x10
        jmp short $-54
L8F:
        mov ax,0x1
        push ax
        mov ax,0x6d
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+20
        mov ax,0x12
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        jmp short $-79
LB5:
        mov ax,0x6d
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x13
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+68
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        mov ax,0xa
        push ax
        mov ax,0x6d
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0x6d
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
L12D:
        mov ax,0x2e
        push ax
        call far ptr helper_5
        add sp,0x2
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x6d
        push ax
        call far ptr helper_6
        add sp,0x6
        jmp L64
L14F:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x15
        jmp L57
L167:
        xor ax,ax
L169:
    }
}
