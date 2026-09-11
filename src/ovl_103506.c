extern char __near mb030C;

int far ovl_103506(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+23
        cmp byte ptr mb030C,0x0
        jz short $+8
        mov ax,0x2492
        jmp short $+6
        nop
L13:
        mov ax,0x2498
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
