extern int __near mn4244;

int far exe_82883(void)
{
    _asm {
        cmp word ptr mn4244,0x0
        jl short $+7
        mov ax,0x1
        jmp short $+4
L0C:
        xor ax,ax
L0E:
        retf
    }
}
