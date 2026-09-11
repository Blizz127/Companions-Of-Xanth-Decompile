
int far exe_98285(int a)
{
    _asm {
        mov ax,0x7
        mov cx,[bp+0x6]
        shl cx,1
        mov dx,[bp+0xa]
        shl dx,1
        int 0x33
        mov ax,0x8
        mov cx,[bp+0x8]
        mov dx,[bp+0xc]
        int 0x33
    }
}
