extern int __near mn6A06;
void far helper_0(void);
int far ovl_148534(int a)
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
        sub al,0x27
        jz short $+9
        sub al,0xa
        jz short $+25
        jmp short $+35
        nop
L21:
        mov ax,0x4
L24:
        mov dx,0xf018
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+16
L35:
        mov ax,0x5
        jmp short $-20
        nop
L3B:
        mov ax,0x6
        jmp short $-26
        nop
L41:
        xor ax,ax
L43:
    }
}
