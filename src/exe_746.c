extern int __near mn4000;
extern int __near mn3FFC;

int far exe_746(void)
{
    _asm {
        mov ax,mn4000
        or ax,ax
        jnz short $+8
        mov ax,0xffff
        jmp short $+33
        nop
L0D:
        cli
        dec word ptr mn4000
        mov bx,mn3FFC
        mov cl,[bx]
        inc bx
        cmp bx,0x627c
        jc short $+5
        mov bx,0x5e7c
L22:
        mov mn3FFC,bx
        sub ax,ax
        mov al,cl
        sti
L2B:
        retf
    }
}
