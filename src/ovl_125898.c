extern int __near mn02A6;

int far ovl_125898(void)
{
    _asm {
        cmp word ptr mn02A6,0x2
        jnl short $+7
        mov ax,0x1
        jmp short $+4
L0C:
        xor ax,ax
L0E:
        retf
    }
}
