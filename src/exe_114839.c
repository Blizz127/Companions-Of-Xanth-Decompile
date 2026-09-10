void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_114839(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x02
        _emit 0x56
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x7D
        _emit 0x06
        _emit 0xA1
        _emit 0xE0
        _emit 0x51
        _emit 0x89
        _emit 0x46
        _emit 0x06
        _emit 0x8B
        _emit 0x5E
        _emit 0x06
        _emit 0x03
        _emit 0xDB
        _emit 0xFF
        _emit 0xB7
        _emit 0x10
        _emit 0x68
        _emit 0x8B
        _emit 0xF3
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xA1
        _emit 0xDA
        _emit 0x6D
        _emit 0x89
        _emit 0x84
        _emit 0xA0
        _emit 0x68
        _emit 0xA1
        _emit 0x48
        _emit 0x6D
        _emit 0x89
        _emit 0x84
        _emit 0xB0
        _emit 0x68
        _emit 0xC7
        _emit 0x84
        _emit 0xC0
        _emit 0x68
        _emit 0xFF
        _emit 0xFF
        _emit 0xFF
        _emit 0xB4
        _emit 0x30
        _emit 0x68
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x89
        _emit 0x46
        _emit 0xFE
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x5E
    }
}
