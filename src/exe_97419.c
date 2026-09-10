void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_97419(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x06
        call far ptr helper_0
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x89
        _emit 0x46
        _emit 0xFC
        _emit 0x89
        _emit 0x56
        _emit 0xFE
        _emit 0x0B
        _emit 0xD0
        _emit 0x74
        _emit 0x0E
        _emit 0xC4
        _emit 0x5E
        _emit 0xFC
        _emit 0x26
        _emit 0xC7
        _emit 0x47
        _emit 0x04
        _emit 0xFF
        _emit 0xFF
        _emit 0x26
        _emit 0xC6
        _emit 0x47
        _emit 0x0A
        _emit 0x10
        call far ptr helper_2
        _emit 0x89
        _emit 0x46
        _emit 0xFA
        _emit 0xA1
        _emit 0xE0
        _emit 0x63
        _emit 0x39
        _emit 0x46
        _emit 0xFA
        _emit 0x73
        _emit 0x0F
        _emit 0x8B
        _emit 0x46
        _emit 0xFA
        _emit 0xA3
        _emit 0xE0
        _emit 0x63
        _emit 0x3B
        _emit 0x06
        _emit 0xE2
        _emit 0x63
        _emit 0x73
        _emit 0x03
        _emit 0xA3
        _emit 0xE2
        _emit 0x63
        _emit 0x8B
        _emit 0x46
        _emit 0xFE
        _emit 0x0B
        _emit 0x46
        _emit 0xFC
        _emit 0x74
        _emit 0x0D
        _emit 0xC4
        _emit 0x5E
        _emit 0xFC
        _emit 0x26
        _emit 0x8B
        _emit 0x07
        _emit 0x26
        _emit 0x8B
        _emit 0x57
        _emit 0x02
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        _emit 0x33
        _emit 0xC0
        _emit 0x99
    }
}
