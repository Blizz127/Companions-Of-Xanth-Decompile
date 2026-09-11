extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_283046(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+85
        jmp LCB
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LCB
L1A:
        cmp word ptr mn6A04,0x175
        jnz short $+7
        mov ax,0x10
        jmp short $+40
L27:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
L4D:
        mov dx,0xf03f
        push dx
        push ax
        call far ptr helper_1
L57:
        mov sp,bp
        mov ax,0x1
        jmp short $+113
        nop
L5F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+96
        ja short $+100
        sub al,0x7
        jz short $+16
        dec al
        jz short $+54
        sub al,0xb
        jz short $+62
        sub al,0x19
        jz short $+46
        jmp short $+82
L7B:
        cmp word ptr mn0256,0x170
        jnz short $+24
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xf
        jmp short $-74
L99:
        mov ax,0x9
        push ax
        call far ptr helper_2
        jmp short $-75
        nop
LA5:
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $-87
        nop
LB1:
        cmp word ptr mn0256,0x170
        jnz short $+8
        mov ax,0xc
        jmp short $-111
        nop
LBF:
        mov ax,0xd
        jmp short $-117
        nop
LC5:
        mov ax,0xe
        jmp short $-123
        nop
LCB:
        xor ax,ax
LCD:
    }
}
