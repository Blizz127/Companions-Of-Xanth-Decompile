extern int __near mn6A06;
extern char __near mb02F3;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_99270(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+111
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+81
        ja short $+101
        cmp al,0x13
        jz short $+63
        ja short $+13
        sub al,0x7
        jz short $+19
        dec al
        jz short $+47
        jmp short $+85
        nop
L23:
        sub al,0x2c
        jz short $+40
        sub al,0x18
        jz short $+48
        jmp short $+74
L2D:
        cmp byte ptr mb02F3,0x0
        jz short $+7
        mov ax,0x8
        jmp short $+5
L39:
        mov ax,0x9
L3C:
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+44
L4D:
        mov ax,0x7
        jmp short $-20
        nop
L53:
        mov ax,0x4
        jmp short $-26
        nop
L59:
        mov ax,0x5
        jmp short $-32
        nop
L5F:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x6
        jmp short $-55
L75:
        xor ax,ax
L77:
    }
}
