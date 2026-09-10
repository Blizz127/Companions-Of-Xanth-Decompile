void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_89495(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x1A
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x75
        _emit 0x10
        _emit 0xB8
        _emit 0x36
        _emit 0x43
        _emit 0x1E
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xEB
        _emit 0x64
        _emit 0x90
        _emit 0x8D
        _emit 0x46
        _emit 0xEC
        _emit 0x16
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x8D
        _emit 0x46
        _emit 0xEC
        _emit 0x16
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x8D
        _emit 0x46
        _emit 0xE6
        _emit 0x16
        _emit 0x50
        _emit 0x8D
        _emit 0x46
        _emit 0xE8
        _emit 0x16
        _emit 0x50
        _emit 0x8D
        _emit 0x4E
        _emit 0xEA
        _emit 0x16
        _emit 0x51
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x10
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB8
        _emit 0x07
        _emit 0x00
        _emit 0x50
        _emit 0x8B
        _emit 0x46
        _emit 0x0C
        _emit 0x05
        _emit 0x13
        _emit 0x00
        _emit 0x50
        _emit 0x8B
        _emit 0x46
        _emit 0x0A
        _emit 0x05
        _emit 0x17
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        _emit 0xFF
        _emit 0x76
        _emit 0xEA
        call far ptr helper_4
        _emit 0x89
        _emit 0x46
        _emit 0xE8
    }
}
