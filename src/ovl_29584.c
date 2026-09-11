extern int __near mn02AE;

int far ovl_29584(void)
{
    _asm {
        mov bx,mn02AE
        add bx,bx
        add bx,bx
        mov ax,[bx+0x1a7e]
        mov dx,[bx+0x1a80]
        retf
    }
}
