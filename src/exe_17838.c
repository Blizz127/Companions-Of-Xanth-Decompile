void far helper_0(void);
int near exe_17838(void)
{
    _asm {
        _emit 0xB8
        _emit 0xFD
        _emit 0x43
        _emit 0xBA
        _emit 0x03
        _emit 0x00
        _emit 0x52
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x14
        _emit 0x58
        _emit 0xFF
        _emit 0x36
        _emit 0x12
        _emit 0x58
        call far ptr helper_0
        _emit 0x05
        _emit 0xC3
    }
}
