extern int __near mn67C0;
void far helper_0(void);
int far exe_112676(void)
{
    _asm {
        mov ax,0x1
        push ax
        push word ptr mn67C0
        call far ptr helper_0
        add sp,0x4
        mov bx,mn67C0
        add bx,bx
        add bx,bx
        les bx, [bx+0x67c2]
        mov word ptr es:[bx+0xa],0x0
        retf
    }
}
