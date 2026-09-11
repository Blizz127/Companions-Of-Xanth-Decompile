void far helper(void);
int far if16_136051(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+25
        call far ptr helper
        or ax,ax
        jz short $+8
        mov ax,0x28ff
        jmp short $+6
        nop
L15:
        mov ax,0x2908
L18:
        mov dx,ds
        jmp short $+6
        nop
L1D:
        xor ax,ax
        cwd
L20:
    }
}
