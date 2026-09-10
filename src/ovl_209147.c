void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_209147(int a)
{
    _asm {
        _emit 0x83
        _emit 0x7E
        _emit 0x0E
        _emit 0x00
        _emit 0x74
        _emit 0x25
        _emit 0xFF
        _emit 0x36
        _emit 0xFC
        _emit 0x31
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xEB
        _emit 0x12
        _emit 0x90
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_2
    }
}
