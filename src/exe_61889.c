extern int __near mn07E4;

int far exe_61889(void)
{
    _asm {
        cmp word ptr mn07E4,0x1
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L0C:
        xor ax,ax
L0E:
        retf
    }
}
