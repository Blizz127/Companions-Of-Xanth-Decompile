extern int __near mn6A06;
extern char __near mb02F3;
void far helper_0(void);
int far ovl_110565(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+81
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+67
        ja short $+71
        sub al,0x7
        jz short $+17
        dec al
        jz short $+45
        sub al,0xb
        jz short $+47
        sub al,0x19
        jz short $+37
        jmp short $+53
        nop
L25:
        cmp byte ptr mb02F3,0x0
        jnz short $+7
        mov ax,0x20
        jmp short $+5
L31:
        mov ax,0x21
L34:
        mov dx,0xf00a
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+22
L45:
        mov ax,0x22
        jmp short $-20
        nop
L4B:
        mov ax,0x1f
        jmp short $-26
        nop
L51:
        mov ax,0x23
        jmp short $-32
        nop
L57:
        xor ax,ax
L59:
    }
}
