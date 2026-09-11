extern int __near mn6A06;
void far helper_0(void);
int far ovl_255076(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+69
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+55
        ja short $+59
        sub al,0x7
        jz short $+17
        dec al
        jz short $+33
        sub al,0xb
        jz short $+35
        sub al,0x19
        jz short $+25
        jmp short $+41
        nop
L25:
        mov ax,0x29
L28:
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+22
L39:
        mov ax,0x27
        jmp short $-20
        nop
L3F:
        mov ax,0x26
        jmp short $-26
        nop
L45:
        mov ax,0x28
        jmp short $-32
        nop
L4B:
        xor ax,ax
L4D:
    }
}
