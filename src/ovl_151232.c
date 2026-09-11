extern int __near mn6A06;
void far helper_0(void);
int far ovl_151232(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+59
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+45
        ja short $+49
        sub al,0x13
        jz short $+13
        sub al,0x25
        jz short $+29
        sub al,0xc
        jz short $+25
        jmp short $+35
        nop
L21:
        mov ax,0x17
L24:
        mov dx,0xf019
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+16
L35:
        mov ax,0x18
        jmp short $-20
        nop
L3B:
        mov ax,0x19
        jmp short $-26
        nop
L41:
        xor ax,ax
L43:
    }
}
