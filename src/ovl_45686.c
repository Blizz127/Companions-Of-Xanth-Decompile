extern int __near mn5A9C;
extern int __near mn02E4;

int far ovl_45686(void)
{
    _asm {
        mov es, mn5A9C
        mov bx,mn02E4
        add bx,bx
        add bx,bx
        mov ax,es:[bx+0x740]
        mov dx,es:[bx+0x742]
        retf
    }
}
