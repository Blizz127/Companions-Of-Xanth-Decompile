
int far ovl_26977(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr [bp+0x6],0xa
        jl short $+14
        cmp word ptr [bp+0x6],0x14
        jg short $+8
        mov ax,0x1926
        jmp short $+55
        nop
L15:
        mov ax,[bp+0x6]
        mov cx,0xa
        cwd
        idiv cx
        mov ax,dx
        dec ax
        jz short $+16
        dec ax
        jz short $+21
        dec ax
        jz short $+26
        mov word ptr [bp-0x4],0x1932
        jmp short $+24
        nop
L31:
        mov word ptr [bp-0x4],0x1929
        jmp short $+16
        nop
L39:
        mov word ptr [bp-0x4],0x192c
        jmp short $+8
        nop
L41:
        mov word ptr [bp-0x4],0x192f
L46:
        mov ax,[bp-0x4]
L49:
        mov dx,ds
    }
}
