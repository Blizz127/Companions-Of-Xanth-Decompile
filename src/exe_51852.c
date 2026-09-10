void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_51852(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x0A
        _emit 0x83
        _emit 0x7E
        _emit 0x0A
        _emit 0x00
        _emit 0x7E
        _emit 0x4C
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
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x1F
        _emit 0xC4
        _emit 0x5E
        _emit 0xFA
        _emit 0x26
        _emit 0x8B
        _emit 0x47
        _emit 0x04
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x09
        _emit 0x50
        call far ptr helper_1
        _emit 0xEB
        _emit 0x09
        _emit 0x90
        _emit 0x26
        _emit 0xFF
        _emit 0x37
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x83
        _emit 0x46
        _emit 0xFA
        _emit 0x0C
        _emit 0xFF
        _emit 0x4E
        _emit 0xF8
        _emit 0x75
        _emit 0xC6
    }
}
