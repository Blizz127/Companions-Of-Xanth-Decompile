int g;
void far helper1(void);
void far helper2(void);
int far if15_167004(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x55
        mov ax, 13h
        push ax
        call far ptr helper1
        mov sp, bp
        or ax, ax
        _emit 0x74
        _emit 0x14
        mov ax, 5A04h
        push ax
        mov ax, 2FDh
        push ax
        call far ptr helper2
        mov sp, bp
        xor ax, ax
        _emit 0xEB
        _emit 0x36
        _emit 0x90
        mov ax, 14h
        push ax
        call far ptr helper1
        mov sp, bp
        or ax, ax
        _emit 0x74
        _emit 0x23
        cmp word ptr g, 8
        _emit 0x7D
        _emit 0x0A
        mov ax, 5A03h
        push ax
        mov ax, 145h
        _emit 0xEB
        _emit 0xD4
        _emit 0x90
        mov ax, 5A04h
        push ax
        mov ax, 2FDh
        push ax
        call far ptr helper2
        add sp, 4
        _emit 0xEB
        _emit 0xC9
        mov ax, 0C5h
    }
}
