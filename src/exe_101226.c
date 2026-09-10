void far helper_0(void);
int far exe_101226(int a)
{
    _asm {
        _emit 0xB8
        _emit 0x6A
        _emit 0x4F
        _emit 0x1E
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x09
        _emit 0xC7
        _emit 0x06
        _emit 0xB2
        _emit 0x67
        _emit 0x00
        _emit 0x00
        _emit 0xEB
        _emit 0x1D
        _emit 0x90
        _emit 0xB8
        _emit 0x71
        _emit 0x4F
        _emit 0x1E
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x06
        _emit 0xC7
        _emit 0x06
        _emit 0xB4
        _emit 0x67
        _emit 0x00
        _emit 0x00
    }
}
