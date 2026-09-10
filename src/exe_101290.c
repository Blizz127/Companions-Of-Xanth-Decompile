void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far exe_101290(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x08
        _emit 0xC7
        _emit 0x06
        _emit 0xB2
        _emit 0x67
        _emit 0xFF
        _emit 0xFF
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xA3
        _emit 0xB4
        _emit 0x67
        _emit 0x39
        _emit 0x46
        _emit 0x06
        _emit 0x7E
        _emit 0x31
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x8B
        _emit 0x56
        _emit 0x0A
        _emit 0x05
        _emit 0x04
        _emit 0x00
        _emit 0x89
        _emit 0x46
        _emit 0xFA
        _emit 0x89
        _emit 0x56
        _emit 0xFC
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x48
        _emit 0x89
        _emit 0x46
        _emit 0xF8
        _emit 0xC4
        _emit 0x5E
        _emit 0xFA
        _emit 0x26
        _emit 0xFF
        _emit 0x77
        _emit 0x02
        _emit 0x26
        _emit 0xFF
        _emit 0x37
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x83
        _emit 0x46
        _emit 0xFA
        _emit 0x04
        _emit 0xFF
        _emit 0x4E
        _emit 0xF8
        _emit 0x75
        _emit 0xE5
        _emit 0x83
        _emit 0x3E
        _emit 0xB2
        _emit 0x67
        _emit 0xFF
        _emit 0x75
        _emit 0x1D
        _emit 0xB8
        _emit 0x00
        _emit 0x00
        _emit 0xB9
        _emit 0xC4
        _emit 0x2E
        _emit 0x51
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x83
        _emit 0x3E
        _emit 0xB2
        _emit 0x67
        _emit 0xFF
        _emit 0x75
        _emit 0x06
        _emit 0xC7
        _emit 0x06
        _emit 0xB2
        _emit 0x67
        _emit 0x01
        _emit 0x00
        call far ptr helper_1
        _emit 0xFF
        _emit 0x36
        _emit 0xB2
        _emit 0x67
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x83
        _emit 0x3E
        _emit 0xB4
        _emit 0x67
        _emit 0x00
        _emit 0x74
        _emit 0x05
        call far ptr helper_3
        call far ptr helper_4
        call far ptr helper_5
    }
}
