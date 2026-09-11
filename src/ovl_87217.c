extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_87217(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+71
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+57
        ja short $+61
        sub al,0x8
        jz short $+13
        sub al,0xa
        jz short $+29
        dec al
        jz short $+37
        jmp short $+47
        nop
L21:
        mov ax,0x17
L24:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_0
L2E:
        mov sp,bp
        mov ax,0x1
        jmp short $+28
L35:
        mov ax,0x3
        push ax
        call far ptr helper_1
        jmp short $-16
        nop
L41:
        mov ax,0x16
        jmp short $-32
        nop
L47:
        mov ax,0x18
        jmp short $-38
        nop
L4D:
        xor ax,ax
L4F:
    }
}
