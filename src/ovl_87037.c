extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_87037(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+55
        jmp LAB
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LAB
L1A:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x15
L2E:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+112
        nop
        nop
L41:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+94
        ja short $+98
        cmp al,0x2c
        jz short $+36
        ja short $+12
        sub al,0x6
        jz short $+18
        sub al,0xd
        jz short $+20
        jmp short $+82
L5B:
        sub al,0x3f
        jz short $+42
        sub al,0x5
        jz short $+44
        jmp short $+72
L65:
        mov ax,0x10
        jmp short $-58
        nop
L6B:
        mov ax,0xf
        jmp short $-64
        nop
L71:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x13
        jmp short $-87
L87:
        mov ax,0x11
        jmp short $-92
        nop
L8D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
        jmp short $-116
        nop
LA5:
        mov ax,0x12
        jmp short $-122
        nop
LAB:
        xor ax,ax
LAD:
    }
}
