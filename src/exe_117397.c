extern int __near mn51E0;

int far exe_117397(int a)
{
    _asm {
        sub sp,0x4
        mov bx,mn51E0
        add bx,bx
        add bx,bx
        mov ax,[bx+0x6960]
        mov dx,[bx+0x6962]
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        or dx,ax
        jz short $+18
        les bx, [bp-0x4]
        cmp word ptr es:[bx+0x2c],0x1
        jnz short $+8
        mov ax,0x1
        jmp short $+5
        nop
L2D:
        xor ax,ax
L2F:
    }
}
