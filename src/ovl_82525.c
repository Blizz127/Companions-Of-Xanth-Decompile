extern int __near mn6A06;
void far helper_0(void);
int far ovl_82525(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+83
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+69
        ja short $+73
        cmp al,0x2e
        jz short $+51
        ja short $+13
        sub al,0x13
        jz short $+19
        sub al,0x17
        jz short $+35
        jmp short $+57
        nop
L23:
        sub al,0x3f
        jz short $+40
        sub al,0x5
        jz short $+30
        jmp short $+46
L2D:
        mov ax,0x2f
L30:
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+28
L41:
        mov ax,0x30
        jmp short $-20
        nop
L47:
        mov ax,0x2e
        jmp short $-26
        nop
L4D:
        mov ax,0x31
        jmp short $-32
        nop
L53:
        mov ax,0x32
        jmp short $-38
        nop
L59:
        xor ax,ax
L5B:
    }
}
