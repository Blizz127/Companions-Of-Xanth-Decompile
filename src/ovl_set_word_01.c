extern int __near mn02A8;
int g;
void far set_word_01(void)
{
    _asm {
        mov ax,[bp+0x8]
        or ax,ax
        jz short $+8
        dec ax
        jz short $+13
        jmp short $+17
        nop
L0D:
        mov word ptr mn02A8,0x5
        jmp short $+8
L15:
        mov word ptr mn02A8,0x6
L1B:
    }
}
