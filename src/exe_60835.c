void far helper_0(void);
int far exe_60835(void)
{
    _asm {
        _emit 0xB8
        _emit 0x18
        _emit 0x00
        _emit 0xB9
        _emit 0x5E
        _emit 0x23
        _emit 0x51
        _emit 0x50
        _emit 0xB8
        _emit 0x03
        _emit 0x00
        _emit 0xBA
        _emit 0x07
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xCB
    }
}
