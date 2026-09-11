extern char __near mb02F2;
char g;
int far if15_131968(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+17
        cmp byte ptr mb02F2,0x1
        sbb ax,ax
        and al,0xfd
        add ax,0x9d
        jmp short $+6
        nop
L15:
        mov ax,0x9d
L18:
    }
}
