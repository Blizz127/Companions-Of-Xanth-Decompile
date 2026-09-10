void far helper_0(void);
int far exe_1835(int a)
{
    _asm {
        _emit 0xC7
        _emit 0x06
        _emit 0xED
        _emit 0x40
        _emit 0x00
        _emit 0x00
        _emit 0xFE
        _emit 0x06
        _emit 0xEC
        _emit 0x40
        _emit 0xB4
        _emit 0x95
        call far ptr helper_0
        _emit 0xB9
        _emit 0xFF
        _emit 0xFF
        _emit 0x83
        _emit 0x3E
        _emit 0xED
        _emit 0x40
        _emit 0x00
        _emit 0x75
        _emit 0x02
        _emit 0xE2
        _emit 0xF7
        _emit 0xFA
        _emit 0xC7
        _emit 0x06
        _emit 0xED
        _emit 0x40
        _emit 0x00
        _emit 0x00
        _emit 0xFB
    }
}
