void far helper_0(void);
int far ovl_52444(int a)
{
    _asm {
        sub sp,0x4
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        or dx,ax
        jz short $+25
        cmp word ptr [bp+0xa],0x0
        jz short $+12
        les bx, [bp-0x4]
        or byte ptr es:[bx],0x1
        jmp short $+10
        nop
L2B:
        les bx, [bp-0x4]
        and byte ptr es:[bx],0xfe
L32:
    }
}
