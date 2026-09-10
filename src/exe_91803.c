void far helper_0(void);
int far exe_91803(void)
{
    _asm {
        _emit 0xFF
        _emit 0x36
        _emit 0x38
        _emit 0x4D
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x0B
        _emit 0xC0
        _emit 0x7D
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0xEB
        _emit 0x08
        _emit 0x8B
        _emit 0xD8
        _emit 0x03
        _emit 0xD8
        _emit 0x8B
        _emit 0x87
        _emit 0x7C
        _emit 0x63
        _emit 0xCB
    }
}
