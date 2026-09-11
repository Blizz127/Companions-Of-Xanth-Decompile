
int far ovl_3542(int a)
{
    _asm {
        sub sp,0x2
        mov ax,[bp+0x8]
        sub ax,0x14
        cmp ax,0x10
        jnl short $+13
        mov ax,[bp+0x8]
        sub ax,0x14
L14:
        mov [bp-0x2],ax
        jmp short $+27
L19:
        mov ax,0xb4
        sub ax,[bp+0x8]
        cmp ax,0x10
        jnl short $+11
        mov ax,0xb4
        sub ax,[bp+0x8]
        jmp short $-22
        nop
L2D:
        mov word ptr [bp-0x2],0xf
L32:
        cmp word ptr [bp+0x6],0x2
        jnz short $+7
        mov ax,[bp-0x2]
        jmp short $+10
L3D:
        mov bx,[bp-0x2]
        mov al,[bx+0x1752]
        cbw
L45:
    }
}
