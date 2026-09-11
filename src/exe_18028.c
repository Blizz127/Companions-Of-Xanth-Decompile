
int far exe_18028(int a)
{
    _asm {
        mov ah,[bp+0x6]
        mov dl,ah
        and dl,0xf
        int 0x16
        jnz short $+11
        cmp dl,0x1
        jnz short $+6
        xor ax,ax
        jmp short $+12
L15:
        cmp dl,0x2
        jz short $+7
        or ax,ax
        jnz short $+3
        dec ax
L1F:
    }
}
