extern int __near mn0256;
extern char __near mb032B;

int far exe_61331(void)
{
    _asm {
        cmp word ptr mn0256,0xed
        jnz short $+14
        cmp byte ptr mb032B,0x0
        jnz short $+7
        mov ax,0x9ac
        jmp short $+5
L14:
        mov ax,0x5a03
L17:
        retf
    }
}
