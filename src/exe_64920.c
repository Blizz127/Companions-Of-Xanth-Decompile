void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_64920(int a)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x75
        _emit 0x03
        _emit 0xE9
        _emit 0x2E
        _emit 0x00
        _emit 0xC6
        _emit 0x06
        _emit 0x42
        _emit 0x5E
        _emit 0x18
        _emit 0xC7
        _emit 0x06
        _emit 0x5E
        _emit 0x5E
        _emit 0x00
        _emit 0x20
        _emit 0xB8
        _emit 0x08
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xC6
        _emit 0x06
        _emit 0x41
        _emit 0x5E
        _emit 0x1F
        _emit 0xC7
        _emit 0x06
        _emit 0x5C
        _emit 0x5E
        _emit 0x00
        _emit 0x20
        _emit 0xB8
        _emit 0x07
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0xA2
        _emit 0x7B
        _emit 0x5E
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x75
        _emit 0x03
        _emit 0xE9
        _emit 0x06
        _emit 0x00
        _emit 0xB8
        _emit 0x0B
        _emit 0x00
        _emit 0xE9
        _emit 0x03
        _emit 0x00
        _emit 0xB8
        _emit 0x09
        _emit 0x00
        _emit 0xA3
        _emit 0x76
        _emit 0x5E
        _emit 0xC6
        _emit 0x06
        _emit 0x38
        _emit 0x5E
        _emit 0x00
        call far ptr helper_1
        call far ptr helper_2
        _emit 0x5F
        _emit 0x5E
    }
}
