void far helper_0(void);
void far helper_1(void);
int far exe_57304(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x7E
        _emit 0x2E
        _emit 0xA1
        _emit 0x4C
        _emit 0x08
        _emit 0x39
        _emit 0x46
        _emit 0x06
        _emit 0x7F
        _emit 0x26
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x89
        _emit 0x56
        _emit 0xFE
        _emit 0x0B
        _emit 0xD0
        _emit 0x75
        _emit 0x0E
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x89
        _emit 0x56
        _emit 0xFE
        _emit 0x8B
        _emit 0x56
        _emit 0xFE
        _emit 0xEB
        _emit 0x06
        _emit 0x90
        _emit 0xB8
        _emit 0x37
        _emit 0x07
        _emit 0x8C
        _emit 0xDA
    }
}
