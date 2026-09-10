void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_101662(int a)
{
    _asm {
        _emit 0xA1
        _emit 0x62
        _emit 0x4F
        _emit 0x0B
        _emit 0x06
        _emit 0x60
        _emit 0x4F
        _emit 0x74
        _emit 0x13
        _emit 0xFF
        _emit 0x36
        _emit 0x62
        _emit 0x4F
        _emit 0xFF
        _emit 0x36
        _emit 0x60
        _emit 0x4F
        _emit 0xB8
        _emit 0x1C
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xFF
        _emit 0x36
        _emit 0x5E
        _emit 0x4F
        _emit 0xFF
        _emit 0x36
        _emit 0x5C
        _emit 0x4F
        _emit 0xB8
        _emit 0x1B
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xFF
        _emit 0x36
        _emit 0x66
        _emit 0x4F
        _emit 0xFF
        _emit 0x36
        _emit 0x64
        _emit 0x4F
        _emit 0xB8
        _emit 0x23
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x83
        _emit 0x3E
        _emit 0x44
        _emit 0x4F
        _emit 0x00
        _emit 0x74
        _emit 0x11
        _emit 0xFF
        _emit 0x36
        _emit 0x44
        _emit 0x4F
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xC7
        _emit 0x06
        _emit 0x44
        _emit 0x4F
        _emit 0x00
        _emit 0x00
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x74
        _emit 0x08
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_2
    }
}
