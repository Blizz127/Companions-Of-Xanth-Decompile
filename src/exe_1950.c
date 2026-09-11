
int far exe_1950(int a)
{
    _asm {
        sub bx,bx
        mov cx,0x10
lbl06:
        test byte ptr [bx+0x407c],0x1
        jnz short $+43
        cli
        mov byte ptr [bx+0x407c],0x1
        les si, [bp+0x6]
        mov [bx+0x407f],si
        mov word ptr [bx+0x4081],es
        mov word ptr es:[si],0x0
        mov ax,[bp+0xa]
        mov [bx+0x407d],ax
        or ax,ax
        jnz short $+18
        mov word ptr es:[si],0xff
        jmp short $+11
        nop
lbl36:
        add bx,0x7
        loop lbl06
        mov bx,0xffff
lbl3E:
        sti
        mov ax,bx
    }
}
