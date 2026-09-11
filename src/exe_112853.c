
int far exe_112853(int a)
{
    _asm {
        sub sp,0x4
        mov ax,0x14
        imul word ptr [bp+0x8]
        mov bx,[bp+0x6]
        add bx,bx
        add bx,bx
        les bx, [bx+0x67c2]
        add bx,ax
        mov al,es:[bx]
        cbw
        sub ax,0x3
        jz short $+12
        sub ax,0x4
        jz short $+7
        xor ax,ax
        jmp short $+7
        nop
L29:
        mov ax,es:[bx+0xa]
L2D:
    }
}
