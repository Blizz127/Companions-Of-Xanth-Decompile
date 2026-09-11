extern int __near mn5CE2;
extern int __near mn5CDE;
extern int __near mn5CE0;

int far exe_53332(int a)
{
    _asm {
        mov ax,mn5CE2
        sub ax,0xcd
        jnz short $+45
        mov ax,[bp+0x6]
        dec ax
        jz short $+17
        dec ax
        dec ax
        jz short $+19
        dec ax
        dec ax
        jz short $+21
        dec ax
        dec ax
        jz short $+23
        jmp short $+25
        nop
L1D:
        inc word ptr mn5CDE
        jmp short $+18
L23:
        inc word ptr mn5CE0
        jmp short $+12
L29:
        dec word ptr mn5CDE
        jmp short $+6
L2F:
        dec word ptr mn5CE0
L33:
    }
}
