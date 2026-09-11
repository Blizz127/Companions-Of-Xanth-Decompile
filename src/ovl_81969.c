extern int __near mn6A06;
void far helper_0(void);
int far ovl_81969(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+65
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+51
        ja short $+55
        sub al,0x13
        jz short $+13
        sub al,0x17
        jz short $+29
        sub al,0x1a
        jz short $+31
        jmp short $+41
        nop
L21:
        mov ax,0x16
L24:
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+22
L35:
        mov ax,0x17
        jmp short $-20
        nop
L3B:
        mov ax,0x18
        jmp short $-26
        nop
L41:
        mov ax,0x19
        jmp short $-32
        nop
L47:
        xor ax,ax
L49:
    }
}
