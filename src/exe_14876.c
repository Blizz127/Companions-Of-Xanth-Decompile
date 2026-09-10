void far helper_0(void);
void far helper_1(void);
int far exe_14876(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0x56
        _emit 0xC6
        _emit 0x06
        _emit 0xAC
        _emit 0x69
        _emit 0x49
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x8B
        _emit 0x56
        _emit 0x08
        _emit 0xA3
        _emit 0xA8
        _emit 0x69
        _emit 0x89
        _emit 0x16
        _emit 0xAA
        _emit 0x69
        _emit 0xBE
        _emit 0xA2
        _emit 0x69
        _emit 0x89
        _emit 0x04
        _emit 0x89
        _emit 0x54
        _emit 0x02
        _emit 0x52
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xA3
        _emit 0xA6
        _emit 0x69
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
        _emit 0xB8
        _emit 0xA2
        _emit 0x69
        _emit 0x1E
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x0C
        _emit 0x5E
    }
}
