void far helper_0(void);
int far exe_731(void)
{
    _asm {
        _emit 0xB4
        _emit 0xFF
        call far ptr helper_0
        _emit 0x50
        _emit 0x8B
        _emit 0x16
        _emit 0xF6
        _emit 0x3F
        _emit 0xEC
        _emit 0x58
        _emit 0xCB
    }
}
