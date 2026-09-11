
int far exe_106748(int a)
{
    _asm {
        sub sp,0x8
        cmp word ptr [bp+0xa],0x0
        jng short $+36
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0x6],ax
        mov [bp-0x4],dx
        mov ax,[bp+0xa]
        mov [bp-0x8],ax
L1B:
        les bx, [bp-0x6]
        add word ptr [bp-0x6],0x14
        mov byte ptr es:[bx],0x0
        dec word ptr [bp-0x8]
        jnz short $-14
L2B:
    }
}
