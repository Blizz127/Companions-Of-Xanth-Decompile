extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_82047(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+67
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+53
        ja short $+57
        sub al,0x13
        jz short $+13
        sub al,0x19
        jz short $+37
        sub al,0x18
        jz short $+33
        jmp short $+43
        nop
L21:
        call far ptr helper_0
        push dx
        push ax
        mov ax,0x1a
L2B:
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+17
        nop
L3D:
        mov ax,0x1c
        jmp short $-21
        nop
L43:
        mov ax,0x1b
        jmp short $-27
        nop
L49:
        xor ax,ax
L4B:
    }
}
