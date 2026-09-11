
int far exe_24834(int a)
{
    _asm {
        cmp word ptr [bp+0x8],0x0
        jz short $+22
        cmp word ptr [bp+0x6],0x0
        jnz short $+16
        mov ah,0x49
        mov bx,[bp+0x8]
        mov es,bx
        int 0x21
        mov ax,0x0
        jnc short $+5
L1A:
        mov ax,0x1
L1D:
    }
}
