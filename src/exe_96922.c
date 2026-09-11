void far helper_0(void);
int far exe_96922(int a)
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
        jz short $+22
        les bx, [bp-0x4]
        test byte ptr es:[bx+0xa],0x80
        jz short $+12
        mov ax,es:[bx+0x6]
        mov dx,es:[bx+0x8]
        jmp short $+5
L33:
        xor ax,ax
        cwd
L36:
    }
}
