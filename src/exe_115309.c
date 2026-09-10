void far helper_0(void);
int far exe_115309(void)
{
    _asm {
        _emit 0x8B
        _emit 0x1E
        _emit 0xE0
        _emit 0x51
        _emit 0x03
        _emit 0xDB
        _emit 0xFF
        _emit 0xB7
        _emit 0x10
        _emit 0x68
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x8B
        _emit 0x1E
        _emit 0xE0
        _emit 0x51
        _emit 0x03
        _emit 0xDB
        _emit 0x8B
        _emit 0x87
        _emit 0xB0
        _emit 0x68
        _emit 0x2B
        _emit 0x06
        _emit 0x48
        _emit 0x6D
        _emit 0x89
        _emit 0x87
        _emit 0xC0
        _emit 0x68
        _emit 0xCB
    }
}
