int g;
void far helper(void);
int far exe_94542(int a, int b)
{
    _asm {
        sub sp, 2
        cmp word ptr g, 10h
        _emit 0x7C
        _emit 0x05
        xor ax, ax
        _emit 0xEB
        _emit 0x1A
        _emit 0x90
        mov ax, word ptr g
        mov word ptr [bp-2], ax
        inc word ptr g
        push word ptr b
        push word ptr a
        push ax
        call far ptr helper
        mov ax, word ptr [bp-2]
    }
}
