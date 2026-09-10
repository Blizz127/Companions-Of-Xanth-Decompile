char g;
void far helper_ne(void);
void far if_eq1_flag(int a, int b)
{
    _asm {
        mov ax, word ptr b
        dec ax
        _emit 0x74
        _emit 0x05
        dec ax
        _emit 0x74
        _emit 0x0A
        _emit 0xEB
        _emit 0x16
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
