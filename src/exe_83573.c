void far helper(void);
int far exe_83573(int a)
{
    _asm {
        sub sp, 2
        mov ax, 1
        push ax
        lea ax, word ptr [bp-2]
        push ss
        push ax
        push word ptr a
        call far ptr helper
        add sp, 8
        or ax, ax
        _emit 0x74
        _emit 0x06
        mov ax, word ptr [bp-2]
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        mov ax, 0FFFFh
    }
}
