extern int __near mn5AA2;
extern int __near mn02E4;

int far ovl_46090(void)
{
    _asm {
        mov es, mn5AA2
        mov bx,mn02E4
        add bx,bx
        add bx,bx
        mov ax,es:[bx+0x790]
        mov dx,es:[bx+0x792]
        retf
    }
}
