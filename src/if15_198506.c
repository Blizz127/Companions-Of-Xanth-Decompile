extern char __near mb0329;
char g;
int far if15_198506(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jz short $+15
        cmp byte ptr mb0329,0x1
        cmc
        sbb ax,ax
        and ax,0x105
        jmp short $+15
L13:
        cmp byte ptr mb0329,0x1
        sbb ax,ax
        and ax,0xfefa
        add ax,0x105
L20:
    }
}
