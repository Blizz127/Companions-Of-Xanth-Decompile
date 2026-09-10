void far helper_0(void);
int far exe_6604(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x06
        _emit 0x57
        _emit 0x56
        _emit 0x8B
        _emit 0x76
        _emit 0x06
        _emit 0x1E
        _emit 0x56
        _emit 0xE8
        _emit 0xFE
        _emit 0x06
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x8B
        _emit 0xF8
        _emit 0x8D
        _emit 0x46
        _emit 0x0E
        _emit 0x16
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        _emit 0x1E
        _emit 0x56
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x0C
        _emit 0x89
        _emit 0x46
        _emit 0xFA
        _emit 0x1E
        _emit 0x56
        _emit 0x57
        _emit 0xE8
        _emit 0x5C
        _emit 0x07
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x8B
        _emit 0x46
        _emit 0xFA
        _emit 0x5E
        _emit 0x5F
    }
}
