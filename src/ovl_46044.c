extern int __near mn5A9E;
extern int __near mn02E4;

int far ovl_46044(void)
{
    _asm {
        mov es, mn5A9E
        mov bx,mn02E4
        add bx,bx
        add bx,bx
        mov ax,es:[bx+0x75c]
        mov dx,es:[bx+0x75e]
        retf
    }
}
