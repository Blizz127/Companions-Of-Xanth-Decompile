extern int __near mn6340;

int far exe_84905(void)
{
    _asm {
        les bx, mn6340
        mov al,es:[bx+0xa]
        cbw
        mov cx,ax
        mov al,es:[bx+0x9]
        cbw
        add ax,cx
        retf
    }
}
