extern int __near mn6A06;
extern int __near mn0256;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_154428(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+89
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+75
        ja short $+79
        sub al,0x13
        jz short $+13
        sub al,0x1b
        jz short $+59
        sub al,0x16
        jz short $+55
        jmp short $+65
        nop
L21:
        mov ax,mn0256
        sub ax,0x79
        jz short $+24
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2e
        jmp short $+5
L3F:
        mov ax,0x2d
L42:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+16
L53:
        mov ax,0x2f
        jmp short $-20
        nop
L59:
        mov ax,0x30
        jmp short $-26
        nop
L5F:
        xor ax,ax
L61:
    }
}
