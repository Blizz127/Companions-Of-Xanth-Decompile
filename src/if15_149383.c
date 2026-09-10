char g;
void far helper(void);
void far helper2(void);
int far if15_149383(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x74
        _emit 0x1F
        mov ax, 1
        push ax
        mov ax, 8Bh
        push ax
        call far ptr helper
        mov sp, bp
        or ax, ax
        _emit 0x74
        _emit 0x5B
        cmp byte ptr g, 0
        _emit 0x74
        _emit 0x54
        mov ax, 0BEh
        _emit 0xEB
        _emit 0x57
        cmp byte ptr g, 0
        _emit 0x74
        _emit 0x4D
        mov ax, 1
        push ax
        mov ax, 8Bh
        push ax
        call far ptr helper
        mov sp, bp
        or ax, ax
        _emit 0x74
        _emit 0x3A
        mov ax, 1
        push ax
        mov ax, 0A5h
        push ax
        call far ptr helper
        mov sp, bp
        or ax, ax
        _emit 0x75
        _emit 0x13
        mov ax, 1
        push ax
        mov ax, 0A4h
        push ax
        call far ptr helper
        mov sp, bp
        or ax, ax
        _emit 0x74
        _emit 0xBB
        mov ax, 64Eh
        push ax
        mov ax, 35Dh
        push ax
        call far ptr helper2
        mov sp, bp
        xor ax, ax
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        mov ax, 0FFFFh
    }
}
