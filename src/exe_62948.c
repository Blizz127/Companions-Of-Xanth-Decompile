void far helper_0(void);
int far exe_62948(int a)
{
    _asm {
        sub sp,0x4
        mov ax,0xa
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        mov [bp-0x4],ax
        mov [bp-0x2],dx
L1B:
        mov ax,[bp+0x6]
        cmp [bp-0x4],ax
        jna short $+11
        les bx, [bp-0x4]
        cmp byte ptr es:[bx],0x20
        jz short $+11
L2C:
        les bx, [bp-0x4]
        cmp byte ptr es:[bx],0xa
        jnz short $+12
L35:
        mov byte ptr es:[bx],0x0
        dec word ptr [bp-0x4]
        jmp short $-33
        nop
L3F:
    }
}
