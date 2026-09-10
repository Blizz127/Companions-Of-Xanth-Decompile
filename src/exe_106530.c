void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_106530(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x08
        _emit 0x83
        _emit 0x7E
        _emit 0x0A
        _emit 0x00
        _emit 0x7E
        _emit 0x55
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
        call far ptr helper_1
        _emit 0x8B
        _emit 0xC8
        _emit 0xB0
        _emit 0x32
        _emit 0xC4
        _emit 0x5E
        _emit 0xFA
        _emit 0x26
        _emit 0xF6
        _emit 0x67
        _emit 0x0B
        _emit 0x8B
        _emit 0xD8
        _emit 0x43
        _emit 0x8B
        _emit 0xC1
        _emit 0x99
        _emit 0xF7
        _emit 0xFB
        _emit 0xB0
        _emit 0x32
        _emit 0x8B
        _emit 0x5E
        _emit 0xFA
        _emit 0x26
        _emit 0xF6
        _emit 0x67
        _emit 0x0A
        _emit 0x03
        _emit 0xD0
        _emit 0x52
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x83
        _emit 0x46
        _emit 0xFA
        _emit 0x14
        _emit 0xFF
        _emit 0x4E
        _emit 0xF8
        _emit 0x75
        _emit 0xBD
    }
}
