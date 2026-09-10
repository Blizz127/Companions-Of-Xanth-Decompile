char g;
void far helper_ne(void);
void far if0_range_flag(int a, int b)
{
    _asm {
        mov ax, word ptr b
        or ax, ax
        _emit 0x74
        _emit 0x0B
        dec ax
        _emit 0x74
        _emit 0x1B
        dec ax
        _emit 0x7C
        _emit 0x1D
        _emit 0x70
        _emit 0x1B
        dec ax
        _emit 0x7F
        _emit 0x18
        xor ax, ax
        push ax
        push word ptr b
        push word ptr a
        call far ptr helper_ne
        mov sp, bp
        _emit 0xEB
        _emit 0x06
        _emit 0x90
        mov byte ptr g, 1
    }
}
