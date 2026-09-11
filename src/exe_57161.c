extern int __near mn5A4C;

int far exe_57161(int a)
{
    _asm {
        sub sp,0x4
        mov word ptr [bp-0x2],0x0
        mov word ptr [bp-0x4],0x2c8
L0D:
        mov ax,[bp+0x6]
        mov es, mn5A4C
        mov bx,[bp-0x4]
        cmp es:[bx],ax
        jz short $+19
        inc word ptr [bp-0x2]
        add word ptr [bp-0x4],0x6
        cmp word ptr [bp-0x4],0x4d8
        jc short $-27
        jmp short $+21
        nop
L2D:
        mov bx,[bp-0x2]
        mov ax,bx
        add bx,bx
        add bx,ax
        add bx,bx
        call dword ptr es:[bx+0x2ca]
        jmp short $+4
L3F:
        xor ax,ax
L41:
    }
}
