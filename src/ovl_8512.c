void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_8512(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB9
        _emit 0x67
        _emit 0x17
        _emit 0x1E
        _emit 0x51
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x89
        _emit 0x46
        _emit 0xFC
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x15
        _emit 0xB8
        _emit 0x00
        _emit 0x00
        _emit 0xB9
        _emit 0x1F
        _emit 0x31
        _emit 0x51
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        call far ptr helper_2
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB9
        _emit 0x02
        _emit 0x00
        _emit 0x51
        _emit 0x8D
        _emit 0x4E
        _emit 0xFE
        _emit 0x16
        _emit 0x51
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x0A
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x72
        _emit 0x00
        _emit 0xB9
        _emit 0x20
        _emit 0x34
        _emit 0x51
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x0A
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        call far ptr helper_4
    }
}
