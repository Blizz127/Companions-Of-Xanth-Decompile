char g;
void far helper_ne(void);
void far range_flag_call(int a, int b)
{
    _asm {
        mov ax, word ptr b
        dec ax
        dec ax
        _emit 0x74
        _emit 0x0C
        dec ax
        _emit 0x7C
        _emit 0x1F
        _emit 0x70
        _emit 0x1D
        dec ax
        dec ax
        _emit 0x7E
        _emit 0x0B
        _emit 0xEB
        _emit 0x17
        _emit 0x90
        mov byte ptr g, 1
        _emit 0xEB
        _emit 0x0F
        _emit 0x90
        xor ax, ax
        push ax
        push word ptr b
        push word ptr a
        call far ptr helper_ne
    }
}
