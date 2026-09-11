extern int __near mn6A06;
void far helper_0(void);
int far ovl_188126(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+69
        mov ax,mn6A06
        cmp ax,0x53
        jz short $+55
        ja short $+59
        sub al,0x13
        jz short $+17
        sub al,0x25
        jz short $+33
        sub al,0xc
        jz short $+29
        dec al
        jz short $+31
        jmp short $+41
        nop
L25:
        mov ax,0x28
L28:
        mov dx,0xf01f
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+22
L39:
        mov ax,0x29
        jmp short $-20
        nop
L3F:
        mov ax,0x2a
        jmp short $-26
        nop
L45:
        mov ax,0x2b
        jmp short $-32
        nop
L4B:
        xor ax,ax
L4D:
    }
}
