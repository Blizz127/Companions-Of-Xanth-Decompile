extern int __near mn6A06;
void far helper_0(void);
int far ovl_151150(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+69
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+55
        ja short $+59
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+33
        sub al,0x19
        jz short $+9
        sub al,0x18
        jz short $+31
        jmp short $+41
        nop
L25:
        mov ax,0x15
L28:
        mov dx,0xf019
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+22
L39:
        mov ax,0x13
        jmp short $-20
        nop
L3F:
        mov ax,0x14
        jmp short $-26
        nop
L45:
        mov ax,0x16
        jmp short $-32
        nop
L4B:
        xor ax,ax
L4D:
    }
}
