void far helper_0(void);
int far exe_50349(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x02
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x89
        _emit 0x46
        _emit 0xFE
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x22
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x39
        _emit 0x46
        _emit 0xFE
        _emit 0x74
        _emit 0x14
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x89
        _emit 0x46
        _emit 0xFE
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0xE6
        _emit 0xEB
        _emit 0x06
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xEB
        _emit 0x03
        _emit 0x90
        _emit 0x33
        _emit 0xC0
    }
}
