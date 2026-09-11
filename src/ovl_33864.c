extern int __near mn02AC;
extern int __near mn1B3A;
extern int __near mn1B3C;
extern int __near mn1B3E;
extern int __near mn1B40;
extern int __near mn1B42;
extern int __near mn1B44;

int far ovl_33864(void)
{
    _asm {
        mov ax,mn02AC
        cmp ax,0x15
        jz short $+56
        ja short $+18
        dec al
        jz short $+20
        sub al,0x5
        jz short $+16
        sub al,0x5
        jz short $+22
        sub al,0x5
        jz short $+28
L1A:
        xor ax,ax
        cwd
        jmp short $+38
        nop
L20:
        mov ax,mn1B3A
        mov dx,mn1B3C
        jmp short $+28
        nop
L2A:
        mov ax,mn1B3E
        mov dx,mn1B40
        jmp short $+18
        nop
L34:
        mov ax,mn1B42
        mov dx,mn1B44
        jmp short $+8
        nop
L3E:
        mov ax,0x1b46
        mov dx,ds
L43:
        retf
    }
}
