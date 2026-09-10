void far helper_0(void);
int far exe_90416(void)
{
    _asm {
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x0D
        _emit 0x83
        _emit 0x3E
        _emit 0x36
        _emit 0x4D
        _emit 0xFF
        _emit 0x75
        _emit 0x06
        _emit 0x39
        _emit 0x06
        _emit 0x34
        _emit 0x4D
        _emit 0x74
        _emit 0x03
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
