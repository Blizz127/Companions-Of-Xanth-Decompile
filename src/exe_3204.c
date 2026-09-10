
int near exe_3204(void)
{
    _asm {
        _emit 0x80
        _emit 0xE7
        _emit 0xE0
        _emit 0x80
        _emit 0xFF
        _emit 0xC0
        _emit 0x75
        _emit 0x02
        _emit 0xF8
        _emit 0xC3
    }
}
