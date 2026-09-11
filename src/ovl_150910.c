extern int __near mn6A06;
void far helper_0(void);
int far ovl_150910(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+69
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+55
        ja short $+59
        cmp al,0x2c
        jz short $+23
        ja short $+13
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+33
        jmp short $+43
        nop
L23:
        sub al,0x38
        jz short $+6
        sub al,0xc
        jnz short $+34
L2B:
        mov ax,0xc
L2E:
        mov dx,0xf019
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+16
L3F:
        mov ax,0xb
        jmp short $-20
        nop
L45:
        mov ax,0xd
        jmp short $-26
        nop
L4B:
        xor ax,ax
L4D:
    }
}
