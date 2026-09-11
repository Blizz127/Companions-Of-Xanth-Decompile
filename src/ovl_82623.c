extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_82623(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+95
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+81
        ja short $+85
        cmp al,0x13
        jz short $+57
        ja short $+13
        sub al,0x8
        jz short $+19
        sub al,0xa
        jz short $+35
        jmp short $+69
        nop
L23:
        sub al,0x2c
        jz short $+46
        sub al,0x13
        jz short $+48
        jmp short $+58
L2D:
        mov ax,0x34
L30:
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_0
L3A:
        mov sp,bp
        mov ax,0x1
        jmp short $+40
L41:
        mov ax,0x7
        push ax
        call far ptr helper_1
        jmp short $-16
        nop
L4D:
        mov ax,0x35
        jmp short $-32
        nop
L53:
        mov ax,0x33
        jmp short $-38
        nop
L59:
        mov ax,0x36
        jmp short $-44
        nop
L5F:
        mov ax,0x37
        jmp short $-50
        nop
L65:
        xor ax,ax
L67:
    }
}
