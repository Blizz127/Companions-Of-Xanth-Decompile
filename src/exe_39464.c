void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_39464(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x0C
        call far ptr helper_0
        _emit 0x03
        _emit 0x46
        _emit 0x06
        _emit 0x83
        _emit 0xD2
        _emit 0x00
        _emit 0x89
        _emit 0x46
        _emit 0xF4
        _emit 0x89
        _emit 0x56
        _emit 0xF6
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x74
        _emit 0x07
        call far ptr helper_1
        _emit 0xEB
        _emit 0x05
        call far ptr helper_2
        _emit 0xC7
        _emit 0x46
        _emit 0xF8
        _emit 0x00
        _emit 0x00
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x74
        _emit 0x11
        call far ptr helper_0
        _emit 0x3B
        _emit 0x56
        _emit 0xF6
        _emit 0x7F
        _emit 0x1C
        _emit 0x7C
        _emit 0x05
        _emit 0x3B
        _emit 0x46
        _emit 0xF4
        _emit 0x73
        _emit 0x15
        _emit 0x8D
        _emit 0x46
        _emit 0xF8
        _emit 0x16
        _emit 0x50
        _emit 0xB8
        _emit 0x05
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0xD4
        call far ptr helper_4
        _emit 0x83
        _emit 0x7E
        _emit 0xF8
        _emit 0x01
        _emit 0x75
        _emit 0x05
        _emit 0x8B
        _emit 0x46
        _emit 0xFE
        _emit 0xEB
        _emit 0x02
        _emit 0x33
        _emit 0xC0
    }
}
