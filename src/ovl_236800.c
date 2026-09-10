void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_236800(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x08
        _emit 0x57
        _emit 0x56
        call far ptr helper_0
        _emit 0xA1
        _emit 0x08
        _emit 0x5B
        _emit 0x8B
        _emit 0xC8
        _emit 0x03
        _emit 0xC0
        _emit 0x03
        _emit 0xC1
        _emit 0x05
        _emit 0x24
        _emit 0x6A
        _emit 0xB9
        _emit 0xAF
        _emit 0x38
        _emit 0x89
        _emit 0x46
        _emit 0xF8
        _emit 0x89
        _emit 0x4E
        _emit 0xFA
        _emit 0xC7
        _emit 0x46
        _emit 0xFC
        _emit 0x08
        _emit 0x00
        _emit 0xBE
        _emit 0xCA
        _emit 0x32
        _emit 0xC4
        _emit 0x7E
        _emit 0xF8
        _emit 0xA5
        _emit 0xA5
        _emit 0xA5
        _emit 0xA5
        _emit 0xA4
        _emit 0xC7
        _emit 0x06
        _emit 0x4E
        _emit 0x4F
        _emit 0x01
        _emit 0x00
        call far ptr helper_1
        call far ptr helper_2
        call far ptr helper_2
        call far ptr helper_2
        _emit 0xBE
        _emit 0xC0
        _emit 0x32
        _emit 0xC4
        _emit 0x7E
        _emit 0xF8
        _emit 0xA5
        _emit 0xA5
        _emit 0xA5
        _emit 0xA5
        _emit 0xA4
        _emit 0xC7
        _emit 0x06
        _emit 0x4E
        _emit 0x4F
        _emit 0x01
        _emit 0x00
        call far ptr helper_1
        call far ptr helper_2
        call far ptr helper_2
        call far ptr helper_2
        _emit 0xFF
        _emit 0x4E
        _emit 0xFC
        _emit 0x75
        _emit 0xB1
        _emit 0xB8
        _emit 0xE8
        _emit 0x03
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_4
        _emit 0x5E
        _emit 0x5F
    }
}
