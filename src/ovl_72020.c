extern char __near mb0324;
extern char __near mb036E;

int far ovl_72020(void)
{
    _asm {
        cmp byte ptr mb0324,0x0
        jz short $+15
        cmp byte ptr mb036E,0x0
        jnz short $+8
        mov ax,0x1
        jmp short $+5
        nop
L14:
        xor ax,ax
L16:
        retf
    }
}
