extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb0324;
extern char __near mb036E;
extern char __near mb036F;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_78923(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L145
L0E:
        mov ax,mn6A06
        cmp ax,0x49
        jnz short $+5
        jmp LEB
L19:
        jna short $+5
        jmp L145
L1E:
        cmp al,0x2c
        jz short $+37
        ja short $+13
        sub al,0x8
        jz short $+31
        sub al,0xb
        jz short $+49
        jmp L145
L2F:
        sub al,0x3a
        jz short $+42
        sub al,0xa
        jnz short $+5
        jmp LDF
L3A:
        dec al
        jnz short $+5
        jmp LE5
L41:
        jmp L145
        nop
L45:
        mov ax,0x1b
L48:
        mov dx,0xf032
        push dx
        push ax
        call far ptr helper_0
L52:
        add sp,0x4
L55:
        mov ax,0x1
        jmp L147
L5B:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1fff
        push ds
        push ax
        call far ptr helper_0
        add sp,0x8
        cmp byte ptr mb0324,0x0
        jz short $+64
        cmp byte ptr mb036E,0x0
        jnz short $+51
        cmp byte ptr mb036F,0x0
        jnz short $+44
        mov ax,0x15
        mov dx,0xf032
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x7d0
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x5a
        push ax
        call far ptr helper_3
        add sp,0x2
        jmp short $-98
LB9:
        mov ax,0x14
        jmp short $-116
        nop
LBF:
        mov ax,0xa
        push ax
        mov ax,0x29
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+8
        mov ax,0x16
        jmp L48
LD9:
        mov ax,0x17
        jmp L48
LDF:
        mov ax,0x19
        jmp L48
LE5:
        mov ax,0x1a
        jmp L48
LEB:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x2006
        mov dx,ds
        jmp short $+6
        nop
L107:
        xor ax,ax
        cwd
L10A:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x18
        mov dx,0xf032
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        jmp L52
        nop
L145:
        xor ax,ax
L147:
    }
}
