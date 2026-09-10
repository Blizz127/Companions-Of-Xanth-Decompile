void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_121013(int a)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x02
        call far ptr helper_0
        _emit 0x8D
        _emit 0x46
        _emit 0x0A
        _emit 0x16
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0x8D
        _emit 0x86
        _emit 0xFE
        _emit 0xFD
        _emit 0x16
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x0C
        _emit 0x8D
        _emit 0x86
        _emit 0xFE
        _emit 0xFD
        _emit 0x16
        _emit 0x50
        _emit 0xB8
        _emit 0xFF
        _emit 0xFF
        _emit 0x50
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xC7
        _emit 0x46
        _emit 0xFE
        _emit 0x00
        _emit 0x00
        call far ptr helper_3
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x17
        call far ptr helper_4
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x08
        call far ptr helper_5
        _emit 0x89
        _emit 0x46
        _emit 0xFE
        _emit 0x83
        _emit 0x7E
        _emit 0xFE
        _emit 0x00
        _emit 0x74
        _emit 0xE0
        call far ptr helper_6
        _emit 0x8B
        _emit 0x46
        _emit 0xFE
    }
}
