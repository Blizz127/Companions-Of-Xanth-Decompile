void far helper_0(void);
int far exe_16216(void)
{
    _asm {
        _emit 0x83
        _emit 0x3E
        _emit 0xBA
        _emit 0x69
        _emit 0x00
        _emit 0x75
        _emit 0x09
        call far ptr helper_0
        _emit 0xFF
        _emit 0x06
        _emit 0xBA
        _emit 0x69
        _emit 0xCB
    }
}
