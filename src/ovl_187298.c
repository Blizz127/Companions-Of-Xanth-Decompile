extern char __near mb031E;

int far ovl_187298(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+23
        cmp byte ptr mb031E,0x0
        jz short $+8
        mov ax,0x301b
        jmp short $+6
        nop
L13:
        mov ax,0x3025
L16:
        mov dx,ds
        jmp short $+6
        nop
L1B:
        xor ax,ax
        cwd
L1E:
    }
}
