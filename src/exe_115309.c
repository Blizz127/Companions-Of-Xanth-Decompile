extern int __near mn51E0;
extern int __near mn6D48;
void far helper_0(void);
int far exe_115309(void)
{
    _asm {
        mov bx,mn51E0
        add bx,bx
        push word ptr [bx+0x6810]
        call far ptr helper_0
        add sp,0x2
        mov bx,mn51E0
        add bx,bx
        mov ax,[bx+0x68b0]
        sub ax,mn6D48
        mov [bx+0x68c0],ax
        retf
    }
}
