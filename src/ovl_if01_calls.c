void far helper_ne(void);
void far helper2(void);
void far if01_calls(int a, int b)
{
    _asm {
        mov ax, word ptr b
        or ax, ax
        _emit 0x74
        _emit 0x06
        dec ax
        _emit 0x74
        _emit 0x22
        _emit 0xEB
        _emit 0x2D
        _emit 0x90
        xor ax, ax
        push ax
        push word ptr b
        push word ptr a
        call far ptr helper_ne
        mov sp, bp
        mov ax, 1
        push ax
        push ax
        push word ptr a
        call far ptr helper_ne
        mov sp, bp
        mov ax, 0Ch
        push ax
        mov ax, 3
        push ax
        call far ptr helper2
    }
}
