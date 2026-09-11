void far helper_0(void);
int far exe_94629(int a)
{
    _asm {
        sub sp,0x4
        les bx, [bp+0x6]
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        call far ptr helper_0
        add sp,0x4
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        or dx,ax
        jz short $+47
        les bx, [bp-0x4]
        test byte ptr es:[bx+0xa],0x80
        jz short $+37
        test byte ptr es:[bx+0xa],0x10
        jnz short $+30
        cmp word ptr [bp+0xa],0x0
        jnz short $+9
        and byte ptr es:[bx+0xa],0xdf
        jmp short $+7
L3D:
        or byte ptr es:[bx+0xa],0x20
L42:
        mov al,[bp+0xa]
        les bx, [bp-0x4]
        mov es:[bx+0xb],al
L4C:
    }
}
