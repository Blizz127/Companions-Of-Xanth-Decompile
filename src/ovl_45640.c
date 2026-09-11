extern int __near mn5A98;
extern int __near mn02E4;

int far ovl_45640(void)
{
    _asm {
        mov es, mn5A98
        mov bx,mn02E4
        add bx,bx
        add bx,bx
        mov ax,es:[bx+0x708]
        mov dx,es:[bx+0x70a]
        retf
    }
}
