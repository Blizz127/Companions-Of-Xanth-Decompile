extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_151304(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+85
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+71
        ja short $+75
        cmp al,0x13
        jz short $+59
        ja short $+13
        sub al,0x8
        jz short $+21
        sub al,0xa
        jz short $+37
        jmp short $+59
        nop
L23:
        sub al,0x2c
        jz short $+10
        sub al,0xc
        jz short $+6
        sub al,0xc
        jnz short $+46
L2F:
        mov ax,0x1b
L32:
        mov dx,0xf019
        push dx
        push ax
        call far ptr helper_0
L3C:
        mov sp,bp
        mov ax,0x1
        jmp short $+28
L43:
        mov ax,0x1
        push ax
        call far ptr helper_1
        jmp short $-16
        nop
L4F:
        mov ax,0x1a
        jmp short $-32
        nop
L55:
        mov ax,0x1c
        jmp short $-38
        nop
L5B:
        xor ax,ax
L5D:
    }
}
