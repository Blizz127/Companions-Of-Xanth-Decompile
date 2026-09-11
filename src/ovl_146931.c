extern int __near mn6A06;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
int far ovl_146931(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+91
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+77
        ja short $+81
        sub al,0x13
        jz short $+17
        sub al,0x19
        jz short $+33
        sub al,0x6
        jz short $+35
        sub al,0x12
        jz short $+53
        jmp short $+63
        nop
L25:
        mov ax,0x25
L28:
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+44
L39:
        mov ax,0x27
        jmp short $-20
        nop
L3F:
        push word ptr mn6A02
        mov ax,0x13
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x29
        jmp short $-43
L55:
        mov ax,0x26
        jmp short $-48
        nop
L5B:
        mov ax,0x28
        jmp short $-54
        nop
L61:
        xor ax,ax
L63:
    }
}
