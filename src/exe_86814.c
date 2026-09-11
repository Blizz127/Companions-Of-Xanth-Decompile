extern int __near mn42E0;
extern int __near mn42E4;
extern int __near mn42E2;
extern int __near mn42E6;

int far exe_86814(int a)
{
    _asm {
        mov ax,mn42E0
        cmp [bp+0x6],ax
        jz short $+39
        mov ax,mn42E4
        or ax,mn42E2
        jz short $+30
        cmp word ptr [bp+0x6],0x0
        jz short $+8
        mov ax,mn42E4
        jmp short $+6
        nop
L1D:
        mov ax,0xa000
L20:
        mov mn42E6,ax
        cmp word ptr [bp+0x6],0x1
        sbb ax,ax
        inc ax
        mov mn42E0,ax
L2D:
    }
}
