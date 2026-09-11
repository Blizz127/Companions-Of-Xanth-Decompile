extern int __near mn02DA;

int far ovl_283424(void)
{
    _asm {
        cmp word ptr mn02DA,0x2
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L0C:
        xor ax,ax
L0E:
        retf
    }
}
