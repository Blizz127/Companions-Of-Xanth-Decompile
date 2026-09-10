void far helper_0(void);
void far helper_1(void);
int far exe_86774(void)
{
    _asm {
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xFF
        _emit 0x36
        _emit 0xE4
        _emit 0x42
        _emit 0xFF
        _emit 0x36
        _emit 0xE2
        _emit 0x42
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x2B
        _emit 0xC0
        _emit 0xA3
        _emit 0xE4
        _emit 0x42
        _emit 0xA3
        _emit 0xE2
        _emit 0x42
        _emit 0xCB
    }
}
