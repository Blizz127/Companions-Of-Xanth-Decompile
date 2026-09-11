
int far exe_2021(int a)
{
    _asm {
        mov bx,[bp+0x6]
        mov ax,[bp+0x8]
        cli
        mov [bx+0x407d],ax
        or ax,ax
        jnz short $+11
        les bx, [bx+0x407f]
        mov word ptr es:[bx],0xff
L18:
        sti
    }
}
