extern int __near mn6A06;
extern int __near mn02A6;
void far helper_0(void);
int far ovl_117001(int a)
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
        jz short $+17
        sub al,0x1b
        jz short $+33
        sub al,0x11
        jz short $+35
        sub al,0x5
        jz short $+25
        jmp short $+61
        nop
L25:
        mov ax,0x3e
L28:
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+42
L39:
        mov ax,0x3f
        jmp short $-20
        nop
L3F:
        cmp word ptr mn02A6,0x2
        jl short $+7
        xor ax,ax
        cwd
        jmp short $+8
L4B:
        mov ax,0x42
        mov dx,0xf00c
L51:
        push dx
        push ax
        mov ax,0x41
        jmp short $-46
        nop
L59:
        mov ax,0x40
        jmp short $-52
        nop
L5F:
        xor ax,ax
L61:
    }
}
