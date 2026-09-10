void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_114622(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x74
        _emit 0x05
        call far ptr helper_0
        _emit 0xC7
        _emit 0x46
        _emit 0xFE
        _emit 0x00
        _emit 0x00
        _emit 0x83
        _emit 0x3E
        _emit 0xDE
        _emit 0x51
        _emit 0x00
        _emit 0x7E
        _emit 0x45
        _emit 0xC7
        _emit 0x46
        _emit 0xFC
        _emit 0x60
        _emit 0x68
        _emit 0x8B
        _emit 0x46
        _emit 0xFE
        _emit 0xA3
        _emit 0xE0
        _emit 0x51
        _emit 0x33
        _emit 0xC9
        _emit 0x51
        call far ptr helper_1
        _emit 0x8B
        _emit 0x5E
        _emit 0xFC
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xC7
        _emit 0x07
        _emit 0x00
        _emit 0x00
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x83
        _emit 0x46
        _emit 0xFC
        _emit 0x02
        _emit 0xA1
        _emit 0xDE
        _emit 0x51
        _emit 0xFF
        _emit 0x46
        _emit 0xFE
        _emit 0x39
        _emit 0x46
        _emit 0xFE
        _emit 0x7C
        _emit 0xC0
        _emit 0xC7
        _emit 0x06
        _emit 0xDE
        _emit 0x51
        _emit 0x00
        _emit 0x00
        _emit 0xC7
        _emit 0x06
        _emit 0xE0
        _emit 0x51
        _emit 0xFF
        _emit 0xFF
    }
}
