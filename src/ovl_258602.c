void far helper_0(void);
int far ovl_258602(int a)
{
    _asm {
        sub sp,0x6
        mov word ptr [bp-0x4],0x0
        mov word ptr [bp-0x6],0x3498
L0D:
        mov ax,0x143
        push ax
        mov bx,[bp-0x6]
        push word ptr [bx]
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+5
        inc word ptr [bp-0x4]
L25:
        add word ptr [bp-0x6],0x2
        cmp word ptr [bp-0x6],0x34a2
        jc short $-33
        mov ax,[bp-0x4]
    }
}
