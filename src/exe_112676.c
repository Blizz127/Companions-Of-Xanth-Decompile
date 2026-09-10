void far helper_0(void);
int far exe_112676(void)
{
    _asm {
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0xC0
        _emit 0x67
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x8B
        _emit 0x1E
        _emit 0xC0
        _emit 0x67
        _emit 0x03
        _emit 0xDB
        _emit 0x03
        _emit 0xDB
        _emit 0xC4
        _emit 0x9F
        _emit 0xC2
        _emit 0x67
        _emit 0x26
        _emit 0xC7
        _emit 0x47
        _emit 0x0A
        _emit 0x00
        _emit 0x00
        _emit 0xCB
    }
}
