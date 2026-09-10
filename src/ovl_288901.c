void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_288901(int a)
{
    _asm {
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x10
        _emit 0x75
        _emit 0x3B
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x15
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0xD2
        _emit 0x37
        _emit 0x8C
        _emit 0xDA
        _emit 0xEB
        _emit 0x17
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        call far ptr helper_2
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0xD9
        _emit 0x37
        _emit 0xEB
        _emit 0xE9
        _emit 0x90
        _emit 0x33
        _emit 0xC0
        _emit 0x99
    }
}
