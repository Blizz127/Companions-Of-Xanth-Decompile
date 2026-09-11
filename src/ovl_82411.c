extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_82411(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+99
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+85
        ja short $+89
        cmp al,0x2a
        jz short $+51
        ja short $+13
        sub al,0x8
        jz short $+19
        sub al,0xb
        jz short $+35
        jmp short $+73
        nop
L23:
        sub al,0x2c
        jz short $+8
        sub al,0x13
        jz short $+36
        jmp short $+62
L2D:
        mov ax,0x2c
L30:
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+44
L41:
        mov ax,0x29
        jmp short $-20
        nop
L47:
        mov ax,0x2a
        jmp short $-26
        nop
L4D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x2b
        jmp short $-49
L63:
        mov ax,0x2d
        jmp short $-54
        nop
L69:
        xor ax,ax
L6B:
    }
}
