extern int __near mn634C;

int far exe_87060(void)
{
    _asm {
L00:
        mov dx,mn634C
        in al,dx
        test al,0x8
        jnz short $-7
L09:
        in al,dx
        test al,0x8
        jz short $-3
        retf
    }
}
