extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb0359;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_278427(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LDB
L0F:
        jmp L119
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L119
L1E:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+28
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0xd
        jmp LC9
        nop
        nop
        nop
L4B:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+71
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x11
        push ax
        push word ptr mn6A02
        call far ptr helper_2
        add sp,0x4
        cmp ax,0x1
        sbb ax,ax
        and ax,0x6
        add ax,0x69
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xe
        jmp short $+41
        nop
LA3:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xf
LC9:
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_3
LD3:
        mov sp,bp
        mov ax,0x1
        jmp short $+67
        nop
LDB:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+44
        ja short $+54
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+12
        sub al,0x19
        jnz short $+42
LF1:
        mov ax,0xc
        jmp short $-43
        nop
LF7:
        cmp byte ptr mb0359,0x0
        jz short $+7
        mov ax,0x3689
        jmp short $+5
L103:
        mov ax,0x368f
L106:
        push ds
        push ax
        mov ax,0xb
        jmp short $-66
L10D:
        push word ptr mn6A04
        call far ptr helper_4
        jmp short $-67
        nop
L119:
        xor ax,ax
L11B:
    }
}
