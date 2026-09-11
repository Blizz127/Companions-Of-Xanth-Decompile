
int far exe_1768(int a)
{
    _asm {
        mov bx,[bp+0x6]
        add bx,bx
        cli
        mov ax,[bx+0x404d]
        mov word ptr [bx+0x404d],0x0
        sti
    }
}
