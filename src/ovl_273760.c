extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn0256;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_273760(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LBD
L0F:
        jmp L14F
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L14F
L1E:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+36
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x7
        mov dx,0xf03b
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        jmp short $+102
L53:
        cmp word ptr mn0256,0x160
        jnz short $+42
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x8
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x8
        jmp short $+41
L83:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x9
LAA:
        mov dx,0xf03b
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
LB7:
        mov ax,0x1
        jmp L151
LBD:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L149
LC8:
        jna short $+5
        jmp L14F
LCD:
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+74
        sub al,0x19
        jnz short $+120
LD9:
        cmp word ptr mn0256,0x162
        jnz short $+38
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x4
LF6:
        mov dx,0xf03b
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $-76
L105:
        mov ax,0x8
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x5
        jmp short $-36
        nop
L11D:
        mov ax,0x2
        mov dx,0xf03b
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        cmp word ptr mn0256,0x160
        jnz short $-124
        mov ax,0x3
L138:
        mov dx,0xf03b
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp LB7
        nop
L149:
        mov ax,0x6
        jmp short $-20
        nop
L14F:
        xor ax,ax
L151:
    }
}
