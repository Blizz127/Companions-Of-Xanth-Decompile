void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_2868(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x08
        _emit 0x57
        _emit 0x56
        _emit 0xC7
        _emit 0x46
        _emit 0xF8
        _emit 0x00
        _emit 0x03
        _emit 0x8B
        _emit 0x5E
        _emit 0xF8
        _emit 0x8E
        _emit 0x06
        _emit 0x68
        _emit 0x5A
        _emit 0x26
        _emit 0xFF
        _emit 0x77
        _emit 0x0A
        _emit 0x26
        _emit 0xFF
        _emit 0x77
        _emit 0x10
        _emit 0x26
        _emit 0xFF
        _emit 0x77
        _emit 0x0E
        _emit 0x8B
        _emit 0xF3
        _emit 0x8C
        _emit 0xC7
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x8E
        _emit 0xC7
        _emit 0x26
        _emit 0xFF
        _emit 0x74
        _emit 0x10
        _emit 0x26
        _emit 0xFF
        _emit 0x74
        _emit 0x0E
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x8E
        _emit 0xC7
        _emit 0x2B
        _emit 0xC0
        _emit 0x26
        _emit 0x89
        _emit 0x44
        _emit 0x10
        _emit 0x26
        _emit 0x89
        _emit 0x44
        _emit 0x0E
        _emit 0x83
        _emit 0x46
        _emit 0xF8
        _emit 0x12
        _emit 0x81
        _emit 0x7E
        _emit 0xF8
        _emit 0x5A
        _emit 0x03
        _emit 0x72
        _emit 0xB8
        call far ptr helper_2
        call far ptr helper_3
        _emit 0x5E
        _emit 0x5F
    }
}
