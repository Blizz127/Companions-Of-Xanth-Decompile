extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_96145(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+71
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+57
        ja short $+61
        sub al,0x12
        jz short $+13
        dec al
        jz short $+25
        sub al,0x19
        jz short $+37
        jmp short $+47
        nop
L21:
        mov ax,0x1
        push ax
        call far ptr helper_0
L2A:
        mov sp,bp
        mov ax,0x1
        jmp short $+32
L31:
        mov ax,0x14
L34:
        mov dx,0xf016
        push dx
L38:
        push ax
        call far ptr helper_1
        jmp short $-20
        nop
L41:
        mov ax,0x15
        jmp short $-16
        nop
L47:
        mov ax,0x23a1
        push ds
        jmp short $-19
L4D:
        xor ax,ax
L4F:
    }
}
