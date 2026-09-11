extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_267290(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+55
        jmp L135
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L135
L1A:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x18
L2E:
        mov dx,0xf039
        push dx
L32:
        push ax
        call far ptr helper_1
L38:
        mov sp,bp
        mov ax,0x1
        jmp L137
        nop
L41:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L11D
L4C:
        jna short $+5
        jmp L135
L51:
        cmp al,0x13
        jz short $+56
        ja short $+14
        sub al,0x8
        jz short $+32
        sub al,0xa
        jz short $+34
        jmp L135
        nop
L63:
        sub al,0x21
        jz short $+44
        sub al,0xb
        jnz short $+5
        jmp LF1
L6E:
        sub al,0x18
        jnz short $+5
        jmp LF7
L75:
        jmp L135
        nop
L79:
        mov ax,0x358f
        push ds
        jmp short $-75
L7F:
        mov ax,0x3
        push ax
        call far ptr helper_2
        jmp short $-80
        nop
L8B:
        mov ax,0x11
        jmp short $-96
        nop
L91:
        mov ax,0x15
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x5
        push ax
        mov ax,0x158
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+34
        mov ax,0x158
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+8
        mov ax,0x3593
        push ds
        jmp short $+15
LCF:
        mov ax,0x16
        jmp short $+6
        nop
LD5:
        mov ax,0x17
LD8:
        mov dx,0xf039
        push dx
LDC:
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x2e
        push ax
        call far ptr helper_5
        jmp L38
LF1:
        mov ax,0x13
        jmp L2E
LF7:
        mov ax,0x5
        push ax
        mov ax,0x158
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x3585
        jmp short $+6
        nop
L111:
        mov ax,0x358a
L114:
        push ds
        push ax
        mov ax,0x12
        jmp L2E
        nop
L11D:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
        jmp L2E
L135:
        xor ax,ax
L137:
    }
}
