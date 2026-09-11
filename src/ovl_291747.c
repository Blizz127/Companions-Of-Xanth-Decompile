extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_291747(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp L9B
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L9B
L1A:
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
        mov ax,0x17
L40:
        mov dx,0xf045
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+78
L51:
        mov ax,mn6A06
        cmp ax,0x58
        jz short $+56
        ja short $+66
        cmp al,0x2c
        jz short $+50
        ja short $+12
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+34
        jmp short $+50
L6B:
        sub al,0x45
        jz short $+40
        sub al,0x12
        jnz short $+42
L73:
        cmp word ptr mn6A06,0x8
        jnz short $+7
        mov ax,0x3840
        jmp short $+5
L7F:
        mov ax,0x3846
L82:
        push ds
        push ax
        mov ax,0x15
        jmp short $-71
L89:
        mov ax,0x13
        jmp short $-76
        nop
L8F:
        mov ax,0x14
        jmp short $-82
        nop
L95:
        mov ax,0x16
        jmp short $-88
        nop
L9B:
        xor ax,ax
L9D:
    }
}
