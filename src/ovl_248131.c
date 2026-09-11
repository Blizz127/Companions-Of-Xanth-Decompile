extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb0356;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_248131(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LB1
L0F:
        jmp L18D
        nop
L13:
        mov ax,mn6A06
        dec ax
        dec ax
        jz short $+10
        sub ax,0x36
        jz short $+5
        jmp L18D
L22:
        mov ax,mn6A04
        sub ax,0x127
        jnz short $+5
        jmp L18D
L2D:
        sub ax,0x7
        jz short $+45
        sub ax,0xa
        jz short $+102
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xd
L4B:
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
L55:
        mov sp,bp
L57:
        mov ax,0x1
        jmp L18F
L5D:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+5
        jmp L18D
L73:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xc
        jmp short $-78
L9B:
        mov ax,0x128
        push ax
        push word ptr mn6A04
        push word ptr mn6A06
        call far ptr helper_3
        mov sp,bp
        jmp L18F
LB1:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L187
LBC:
        jna short $+5
        jmp L18D
LC1:
        sub al,0x12
        jz short $+20
        dec al
        jz short $+28
        sub al,0x19
        jnz short $+5
        jmp L16F
LD0:
        sub al,0x16
        jz short $+5
        jmp L18D
LD7:
        mov ax,0xa
        push ax
        call far ptr helper_4
        jmp L55
LE3:
        push word ptr mn6A04
        mov ax,0x12e
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+11
        mov ax,0x6
        mov dx,0xf026
        jmp short $+6
        nop
LFF:
        xor ax,ax
        cwd
L102:
        push dx
        push ax
        mov ax,0x5
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        push word ptr mn6A04
        mov ax,0x138
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+17
        mov ax,0x7
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L135:
        push word ptr mn6A04
        mov ax,0x127
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+5
        jmp L57
L14B:
        mov byte ptr mb0356,0x1
        push word ptr mn6A04
        mov ax,0x12e
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+8
        mov ax,0x8
        jmp L4B
L169:
        mov ax,0x9
        jmp L4B
L16F:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xa
        jmp L4B
        nop
L187:
        mov ax,0xb
        jmp L4B
L18D:
        xor ax,ax
L18F:
    }
}
