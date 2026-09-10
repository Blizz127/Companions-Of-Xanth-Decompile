void far helper(void);
void far helper2(void);
int far if15_255409(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x27
        mov ax, 11h
        push ax
        mov ax, 127h
        push ax
        call far ptr helper
        mov sp, bp
        or ax, ax
        _emit 0x75
        _emit 0x14
        mov ax, 5A03h
        push ax
        mov ax, 16Fh
        push ax
        call far ptr helper2
        mov sp, bp
        xor ax, ax
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        mov ax, 139h
    }
}
