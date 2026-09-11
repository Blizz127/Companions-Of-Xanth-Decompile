extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_270854(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+97
        jmp L111
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L111
L1A:
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+24
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x16
        jmp short $+23
L43:
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x17
L58:
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
L65:
        mov ax,0x1
        jmp L113
L6B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L10B
L76:
        jna short $+5
        jmp L111
L7B:
        sub al,0x13
        jz short $+18
        sub al,0x25
        jz short $+50
        sub al,0x6
        jz short $+102
        sub al,0x6
        jz short $+42
        jmp L111
        nop
L8F:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x35e4
        jmp short $+6
        nop
LA9:
        mov ax,0x35f3
LAC:
        push ds
        push ax
        mov ax,0x10
        jmp short $-89
LB3:
        mov ax,0x11
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $-112
        mov ax,0x12
LDA:
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp L65
        nop
LEB:
        mov ax,0x15c
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x14
        jmp short $-40
        nop
L105:
        mov ax,0x15
        jmp short $-46
        nop
L10B:
        mov ax,0x13
        jmp short $-52
        nop
L111:
        xor ax,ax
L113:
    }
}
