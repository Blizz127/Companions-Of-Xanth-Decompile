void far helper_0(void);
int far exe_106920(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x08
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x0B
        _emit 0x46
        _emit 0x06
        _emit 0x74
        _emit 0x2F
        _emit 0x83
        _emit 0x7E
        _emit 0x0A
        _emit 0x00
        _emit 0x7E
        _emit 0x29
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x8B
        _emit 0x56
        _emit 0x08
        _emit 0x89
        _emit 0x46
        _emit 0xFA
        _emit 0x89
        _emit 0x56
        _emit 0xFC
        _emit 0x8B
        _emit 0x46
        _emit 0x0A
        _emit 0x89
        _emit 0x46
        _emit 0xF8
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        _emit 0xFF
        _emit 0x76
        _emit 0xFA
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x83
        _emit 0x46
        _emit 0xFA
        _emit 0x14
        _emit 0xFF
        _emit 0x4E
        _emit 0xF8
        _emit 0x75
        _emit 0xE9
    }
}
