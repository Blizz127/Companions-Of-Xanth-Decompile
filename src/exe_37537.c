void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_37537(int a)
{
    _asm {
        _emit 0xA1
        _emit 0x56
        _emit 0x00
        _emit 0x39
        _emit 0x46
        _emit 0x06
        _emit 0x74
        _emit 0x49
        _emit 0xC7
        _emit 0x06
        _emit 0xF6
        _emit 0x69
        _emit 0x00
        _emit 0x00
        _emit 0xB8
        _emit 0x34
        _emit 0x00
        _emit 0xB9
        _emit 0x99
        _emit 0x21
        _emit 0x51
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        call far ptr helper_1
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x01
        _emit 0x75
        _emit 0x07
        call far ptr helper_2
        _emit 0xEB
        _emit 0x06
        _emit 0xC7
        _emit 0x06
        _emit 0x58
        _emit 0x00
        _emit 0x01
        _emit 0x00
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0xA3
        _emit 0x56
        _emit 0x00
        _emit 0xB8
        _emit 0x20
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x8B
        _emit 0xE5
        _emit 0xC7
        _emit 0x06
        _emit 0x58
        _emit 0x00
        _emit 0x00
        _emit 0x00
        call far ptr helper_4
    }
}
