extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_179013(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+81
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+67
        ja short $+71
        sub al,0x8
        jz short $+17
        sub al,0xa
        jz short $+33
        dec al
        jz short $+41
        sub al,0x19
        jz short $+43
        jmp short $+53
        nop
L25:
        mov ax,0x4d
L28:
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_0
L32:
        mov sp,bp
        mov ax,0x1
        jmp short $+34
L39:
        mov ax,0xa
        push ax
        call far ptr helper_1
        jmp short $-16
        nop
L45:
        mov ax,0x4b
        jmp short $-32
        nop
L4B:
        mov ax,0x4c
        jmp short $-38
        nop
L51:
        mov ax,0x4e
        jmp short $-44
        nop
L57:
        xor ax,ax
L59:
    }
}
