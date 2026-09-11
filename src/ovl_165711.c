extern char __near mb0320;

int far ovl_165711(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+23
        cmp byte ptr mb0320,0x0
        jz short $+8
        mov ax,0x2bfa
        jmp short $+6
        nop
L13:
        mov ax,0x2c06
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
