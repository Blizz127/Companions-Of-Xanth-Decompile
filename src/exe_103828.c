
int far exe_103828(int a)
{
    _asm {
        mov ax,[bp+0x8]
        or ax,[bp+0x6]
        jz short $+47
        les bx, [bp+0x6]
        cmp byte ptr es:[bx],0x0
        jz short $+38
        mov ax,es:[bx+0x12]
        or ax,es:[bx+0x10]
        jz short $+28
        les bx, es:[bx+0xc]
        mov ax,es:[bx]
        mov dx,es:[bx+0x2]
        les bx, [bp+0x6]
        les bx, es:[bx+0x10]
        mov es:[bx+0x18],ax
        mov es:[bx+0x1a],dx
L35:
    }
}
