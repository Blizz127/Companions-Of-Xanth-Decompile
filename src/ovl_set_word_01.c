int g;
void far set_word_01(void)
{
    _asm {
        mov ax, word ptr [bp+8]
        or ax, ax
        _emit 0x74
        _emit 0x06
        dec ax
        _emit 0x74
        _emit 0x0B
        _emit 0xEB
        _emit 0x0F
        _emit 0x90
        mov word ptr g, 5
        _emit 0xEB
        _emit 0x06
        mov word ptr g, 6
    }
}
