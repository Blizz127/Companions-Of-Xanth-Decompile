extern int __near mn6A06;
void far helper_0(void);
int far ovl_306215(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+61
        mov ax,mn6A06
        cmp ax,0x13
        jz short $+47
        ja short $+9
        sub ax,0x8
        jz short $+19
        jmp short $+44
L19:
        sub ax,0x2c
        jz short $+12
        sub ax,0x18
        jc short $+34
        sub ax,0x1
        ja short $+29
L28:
        mov ax,0x14
L2B:
        mov dx,0xf02f
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+11
        nop
L3D:
        mov ax,0x13
        jmp short $-21
        nop
L43:
        xor ax,ax
L45:
    }
}
