extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_75290(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+85
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+71
        ja short $+75
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+33
        sub al,0x19
        jz short $+9
        sub al,0x18
        jz short $+31
        jmp short $+57
        nop
L25:
        mov ax,0x30
L28:
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+38
L39:
        mov ax,0x2e
        jmp short $-20
        nop
L3F:
        mov ax,0x2e
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x2f
        jmp short $-43
L55:
        mov ax,0x31
        jmp short $-48
        nop
L5B:
        xor ax,ax
L5D:
    }
}
