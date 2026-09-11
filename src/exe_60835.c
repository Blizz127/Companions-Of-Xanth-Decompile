void far helper_0(void);
int far exe_60835(void)
{
    _asm {
        mov ax,0x18
        mov cx,0x235e
        push cx
        push ax
        mov ax,0x3
        mov dx,0xf007
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        retf
    }
}
