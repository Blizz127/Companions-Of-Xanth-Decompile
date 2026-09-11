extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb02F3;
extern char __near mb035D;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far ovl_109219(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L97
L0F:
        jmp L15B
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L15B
L1E:
        cmp word ptr mn6A04,0x9b
        jz short $+93
        cmp word ptr mn6A04,0x88
        jz short $+85
        cmp word ptr mn6A04,0x89
        jz short $+77
        push word ptr mn6A04
        mov ax,0x26
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
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
        mov ax,0x8
L6E:
        mov dx,0xf00a
        push dx
        push ax
        call far ptr helper_1
L78:
        mov sp,bp
        mov ax,0x1
        jmp L15D
        nop
L81:
        push word ptr mn6A02
        push word ptr mn6A04
        mov ax,0x14
        push ax
        call far ptr helper_2
        mov sp,bp
        jmp L15D
L97:
        mov ax,mn6A06
        cmp ax,0x42
        jnz short $+5
        jmp L12F
LA2:
        jna short $+5
        jmp L15B
LA7:
        sub al,0xe
        jz short $+10
        sub al,0x5
        jz short $+48
        jmp L15B
        nop
LB3:
        cmp byte ptr mb02F3,0x0
        jnz short $+7
        mov ax,0x4
        jmp short $-79
LBF:
        mov ax,0x5
        mov dx,0xf00a
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x2
        push ax
        mov ax,0x9
        push ax
        call far ptr helper_3
        jmp short $-99
LDD:
        cmp byte ptr mb035D,0x0
        jz short $+7
        mov ax,0x2
        jmp short $-121
LE9:
        mov byte ptr mb035D,0x1
        mov ax,0x3
        mov dx,0xf00a
        push dx
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x7
        push ax
        call far ptr helper_5
        mov sp,bp
        mov ax,0x1
        push ax
        call far ptr helper_6
        mov sp,bp
        mov ax,0x7d0
        push ax
        call far ptr helper_7
        mov sp,bp
        mov ax,0x5a03
        push ax
        mov ax,0x18c
        push ax
        call far ptr helper_8
        jmp L78
        nop
L12F:
        cmp byte ptr mb02F3,0x0
        jz short $+7
        xor ax,ax
        cwd
        jmp short $+8
L13B:
        mov ax,0x7
        mov dx,0xf00a
L141:
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x6
        jmp L6E
L15B:
        xor ax,ax
L15D:
    }
}
