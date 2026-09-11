extern int __near mn5AA0;
extern int __near mn02E4;

int far ovl_46067(void)
{
    _asm {
        mov es, mn5AA0
        mov bx,mn02E4
        add bx,bx
        add bx,bx
        mov ax,es:[bx+0x778]
        mov dx,es:[bx+0x77a]
        retf
    }
}
