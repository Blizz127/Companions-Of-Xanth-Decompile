extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_291323(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+40
        jmp L10D
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L10D
L1E:
        mov ax,0xc
L21:
        mov dx,0xf045
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
L2E:
        mov ax,0x1
        jmp L10F
        nop
L35:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L107
L40:
        jna short $+5
        jmp L10D
L45:
        cmp al,0x2c
        jnz short $+5
        jmp LE9
L4C:
        ja short $+13
        sub al,0x8
        jz short $+27
        sub al,0xb
        jz short $+101
        jmp L10D
L59:
        sub al,0x38
        jnz short $+5
        jmp LEF
L60:
        sub al,0xc
        jnz short $+5
        jmp LEF
L67:
        jmp L10D
        nop
L6B:
        mov ax,0xe
        push ax
        mov ax,0x187
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+38
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0xa
L94:
        mov dx,0xf045
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp short $-115
LA3:
        xor ax,ax
        push ax
        mov ax,0x187
        push ax
        mov ax,0x57
        push ax
        call far ptr helper_3
        add sp,0x6
        jmp short $+89
        nop
LB9:
        mov ax,0xe
        push ax
        mov ax,0x187
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x3837
        mov dx,ds
        jmp short $+9
        nop
LD5:
        mov ax,0x7
        mov dx,0xf045
LDB:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x6
        jmp short $-82
        nop
LE9:
        mov ax,0x9
        jmp L21
LEF:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x8
        jmp short $-112
        nop
L107:
        mov ax,0xb
        jmp L21
L10D:
        xor ax,ax
L10F:
    }
}
