void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_103944(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x0A
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0xEB
        _emit 0x64
        _emit 0xA1
        _emit 0x54
        _emit 0x4F
        _emit 0x03
        _emit 0x06
        _emit 0x48
        _emit 0x4F
        _emit 0x8B
        _emit 0xC8
        _emit 0x03
        _emit 0x06
        _emit 0x0C
        _emit 0x6E
        _emit 0x48
        _emit 0x50
        _emit 0xA1
        _emit 0x52
        _emit 0x4F
        _emit 0x03
        _emit 0x06
        _emit 0x46
        _emit 0x4F
        _emit 0x8B
        _emit 0xD0
        _emit 0x03
        _emit 0x06
        _emit 0x0A
        _emit 0x6E
        _emit 0x48
        _emit 0x50
        _emit 0x89
        _emit 0x4E
        _emit 0xFA
        _emit 0x51
        _emit 0x89
        _emit 0x56
        _emit 0xFC
        _emit 0x52
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xA0
        _emit 0x09
        _emit 0x6E
        _emit 0x25
        _emit 0x40
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x0A
        _emit 0x6E
        _emit 0xFF
        _emit 0x76
        _emit 0xFA
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x89
        _emit 0x46
        _emit 0xFE
        call far ptr helper_3
        _emit 0x83
        _emit 0x7E
        _emit 0xFE
        _emit 0x00
        _emit 0x75
        _emit 0xA7
        _emit 0xF6
        _emit 0x06
        _emit 0x09
        _emit 0x6E
        _emit 0x10
        _emit 0x74
        _emit 0x05
        call far ptr helper_4
        _emit 0xB8
        _emit 0x01
        _emit 0x00
    }
}
