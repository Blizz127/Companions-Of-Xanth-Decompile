
int far exe_2051(int a)
{
    _asm {
        mov bx,[bp+0x6]
        mov ax,[bp+0x8]
        cli
        add [bx+0x407d],ax
        js short $+4
        jnz short $+11
L0F:
        les bx, [bx+0x407f]
        mov word ptr es:[bx],0xff
L18:
        sti
    }
}
