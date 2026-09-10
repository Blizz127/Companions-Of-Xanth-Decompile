void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far exe_61592(int a)
{
    _asm {
        _emit 0x83
        _emit 0x7E
        _emit 0x0A
        _emit 0x01
        _emit 0x75
        _emit 0x0B
        _emit 0xB8
        _emit 0x04
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0x83
        _emit 0x7E
        _emit 0x0A
        _emit 0x01
        _emit 0x75
        _emit 0x06
        _emit 0xB8
        _emit 0xE6
        _emit 0x07
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        _emit 0xB8
        _emit 0xE8
        _emit 0x07
        _emit 0x1E
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_2
        _emit 0x8B
        _emit 0xE5
        _emit 0xA3
        _emit 0x78
        _emit 0x5D
        _emit 0x89
        _emit 0x16
        _emit 0x7A
        _emit 0x5D
        _emit 0x8B
        _emit 0xC2
        _emit 0x0B
        _emit 0x06
        _emit 0x78
        _emit 0x5D
        _emit 0x75
        _emit 0x17
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0x33
        _emit 0xC0
        _emit 0xBA
        _emit 0x01
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_3
        _emit 0x8B
        _emit 0xE5
        _emit 0xEB
        _emit 0x25
        _emit 0x90
        _emit 0x8B
        _emit 0x46
        _emit 0x0A
        _emit 0xA3
        _emit 0xE4
        _emit 0x07
        _emit 0x48
        _emit 0x75
        _emit 0x1B
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_4
        _emit 0x8B
        _emit 0xE5
        _emit 0x2B
        _emit 0xC0
        _emit 0xA3
        _emit 0x7E
        _emit 0x5D
        _emit 0xA3
        _emit 0x7C
        _emit 0x5D
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_5
    }
}
