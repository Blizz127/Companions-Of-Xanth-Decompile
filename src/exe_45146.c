void far helper(void);
int far exe_45146(int a, int b)
{
    _asm {
        sub sp, 6
        lea ax, word ptr [bp-2]
        push ss
        push ax
        push word ptr b
        push word ptr a
        call far ptr helper
        add sp, 8
        mov word ptr [bp-6], ax
        mov word ptr [bp-4], dx
        or dx, ax
        _emit 0x74
        _emit 0x11
        les bx, dword ptr [bp-6]
        mov cl, byte ptr [bp-2]
        mov al, byte ptr es:[bx]
        shr al, cl
        and ax, 1
        _emit 0xEB
        _emit 0x03
        _emit 0x90
        xor ax, ax
    }
}
