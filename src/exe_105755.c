void far helper_0(void);
void far helper_1(void);
int far exe_105755(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x06
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x89
        _emit 0x46
        _emit 0xFC
        _emit 0x89
        _emit 0x56
        _emit 0xFE
        _emit 0xEB
        _emit 0x22
        _emit 0xFF
        _emit 0x76
        _emit 0x0E
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x0A
        _emit 0x8B
        _emit 0x46
        _emit 0x0E
        _emit 0x01
        _emit 0x46
        _emit 0x06
        _emit 0x81
        _emit 0x46
        _emit 0xFC
        _emit 0x40
        _emit 0x01
        _emit 0x8B
        _emit 0x46
        _emit 0x10
        _emit 0xFF
        _emit 0x4E
        _emit 0x10
        _emit 0x0B
        _emit 0xC0
        _emit 0x7F
        _emit 0xD4
    }
}
