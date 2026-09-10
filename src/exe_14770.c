void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_14770(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0x57
        _emit 0x56
        _emit 0xC6
        _emit 0x06
        _emit 0xA0
        _emit 0x69
        _emit 0x42
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x8B
        _emit 0x56
        _emit 0x08
        _emit 0xA3
        _emit 0x9C
        _emit 0x69
        _emit 0x89
        _emit 0x16
        _emit 0x9E
        _emit 0x69
        _emit 0xBE
        _emit 0x96
        _emit 0x69
        _emit 0x89
        _emit 0x04
        _emit 0x89
        _emit 0x54
        _emit 0x02
        _emit 0xC7
        _emit 0x06
        call far ptr helper_0
        _emit 0x46
        _emit 0x0E
        _emit 0x16
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        _emit 0x1E
        _emit 0x56
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x0C
        _emit 0x8B
        _emit 0xF8
        _emit 0xFF
        _emit 0x0E
        call far ptr helper_2
        _emit 0x1E
        _emit 0x96
        _emit 0x69
        _emit 0xFF
        _emit 0x06
        _emit 0x96
        _emit 0x69
        _emit 0x26
        _emit 0xC6
        _emit 0x07
        _emit 0x00
        _emit 0xEB
        _emit 0x0E
        _emit 0x90
        _emit 0x1E
        _emit 0x56
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x8B
        _emit 0xC7
        _emit 0x5E
        _emit 0x5F
    }
}
