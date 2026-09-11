extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_88499(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+87
        mov ax,mn6A06
        cmp ax,0x52
        jz short $+51
        ja short $+77
        sub al,0x13
        jz short $+13
        sub al,0x31
        jz short $+29
        dec al
        jz short $+31
        jmp short $+63
        nop
L21:
        mov ax,0x2f
L24:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+44
L35:
        mov ax,0x31
        jmp short $-20
        nop
L3B:
        mov ax,0x32
        jmp short $-26
        nop
L41:
        mov ax,0x22f3
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x30
        jmp short $-54
        nop
L5D:
        xor ax,ax
L5F:
    }
}
