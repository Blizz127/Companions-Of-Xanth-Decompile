void far helper_0(void);
int far ovl_211414(int a)
{
    _asm {
        sub sp,0x2
        jmp short $+63
L05:
        test byte ptr [bp-0x2],0x4
        jz short $+12
        les bx, [bp+0x6]
        inc byte ptr es:[bx+0x8]
        jmp short $+48
        nop
L15:
        test byte ptr [bp-0x2],0x40
        jz short $+12
        les bx, [bp+0x6]
        dec byte ptr es:[bx+0x8]
        jmp short $+32
        nop
L25:
        test byte ptr [bp-0x2],0x10
        jz short $+12
        les bx, [bp+0x6]
        inc byte ptr es:[bx+0x7]
        jmp short $+16
        nop
L35:
        test byte ptr [bp-0x2],0x1
        jz short $+9
        les bx, [bp+0x6]
        dec byte ptr es:[bx+0x7]
L42:
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov [bp-0x2],ax
        or ax,ax
        jnz short $-80
    }
}
