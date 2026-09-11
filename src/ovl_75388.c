extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_75388(int a)
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
        jz short $+47
        jmp short $+57
        nop
L25:
        mov ax,0x33
L28:
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+38
L39:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x35
        jmp short $-37
L4F:
        mov ax,0x32
        jmp short $-42
        nop
L55:
        mov ax,0x34
        jmp short $-48
        nop
L5B:
        xor ax,ax
L5D:
    }
}
