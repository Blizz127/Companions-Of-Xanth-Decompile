
int far ovl_132704(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xa7
        jz short $+70
        cmp word ptr [bp+0x6],0xa6
        jz short $+63
        cmp word ptr [bp+0x6],0x76
        jz short $+57
        cmp word ptr [bp+0x6],0x7f
        jz short $+51
        cmp word ptr [bp+0x6],0x6e
        jz short $+45
        cmp word ptr [bp+0x6],0x6f
        jz short $+39
        cmp word ptr [bp+0x6],0xb1
        jz short $+32
        cmp word ptr [bp+0x6],0x7e
        jz short $+26
        cmp word ptr [bp+0x6],0x8f
        jz short $+19
        cmp word ptr [bp+0x6],0x75
        jz short $+13
        cmp word ptr [bp+0x6],0x78
        jz short $+7
        xor al,al
        jmp short $+5
        nop
L4B:
        mov al,0x1
L4D:
    }
}
