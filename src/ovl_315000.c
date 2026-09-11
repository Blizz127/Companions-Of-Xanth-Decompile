extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_315000(int a)
{
    _asm {
        sub sp,0x2
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+76
        jmp L147
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L147
L1E:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x23
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
L52:
        mov ax,0x1
        jmp L149
        nop
L59:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+26
        jna short $+5
        jmp L147
L66:
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+27
        sub al,0x19
        jz short $+9
        sub al,0x18
        jz short $+69
        jmp L147
L79:
        push word ptr mn6A04
        call far ptr helper_2
L82:
        add sp,0x2
        jmp short $-51
L87:
        cmp word ptr mn0256,0x1bd
        jnz short $+30
        mov ax,0xe
        push ax
        mov ax,0x1be
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+10
        mov word ptr [bp-0x2],0x3a52
        jmp short $+8
        nop
LAB:
        mov word ptr [bp-0x2],0x3a5e
LB0:
        push ds
        push word ptr [bp-0x2]
        mov ax,0x20
        jmp short $+43
LB9:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+40
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x21
LE2:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L52
        nop
LF3:
        mov ax,0x1c1
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x22
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_5
        add sp,0x6
        push word ptr mn6A04
        call far ptr helper_6
        jmp L82
        nop
L147:
        xor ax,ax
L149:
    }
}
