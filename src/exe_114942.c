
int far exe_114942(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x0
        jnl short $+12
        xor ax,ax
        les bx, [bp+0x8]
        mov es:[bx],ax
        jmp short $+21
lbl11:
        mov bx,[bp+0x6]
        add bx,bx
        mov ax,[bx+0x6840]
        les si, [bp+0x8]
        mov es:[si],ax
        mov ax,[bx+0x6850]
lbl24:
        les bx, [bp+0xc]
        mov es:[bx],ax
    }
}
