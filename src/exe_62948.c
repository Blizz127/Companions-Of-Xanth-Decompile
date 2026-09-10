void far helper_0(void);
int far exe_62948(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x89
        _emit 0x46
        _emit 0xFC
        _emit 0x89
        _emit 0x56
        _emit 0xFE
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x39
        _emit 0x46
        _emit 0xFC
        _emit 0x76
        _emit 0x09
        _emit 0xC4
        _emit 0x5E
        _emit 0xFC
        _emit 0x26
        _emit 0x80
        _emit 0x3F
        _emit 0x20
        _emit 0x74
        _emit 0x09
        _emit 0xC4
        _emit 0x5E
        _emit 0xFC
        _emit 0x26
        _emit 0x80
        _emit 0x3F
        _emit 0x0A
        _emit 0x75
        _emit 0x0A
        _emit 0x26
        _emit 0xC6
        _emit 0x07
        _emit 0x00
        _emit 0xFF
        _emit 0x4E
        _emit 0xFC
        _emit 0xEB
        _emit 0xDD
        _emit 0x90
    }
}
