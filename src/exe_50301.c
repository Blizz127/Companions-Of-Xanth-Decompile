void far helper_0(void);
void far helper_1(void);
int far exe_50301(int a)
{
    _asm {
        _emit 0x83
        _emit 0x7E
        _emit 0x0A
        _emit 0x00
        _emit 0x7C
        _emit 0x0F
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x3B
        _emit 0x46
        _emit 0x0A
        _emit 0x75
        _emit 0x14
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0x3B
        _emit 0x46
        _emit 0x08
        _emit 0x75
        _emit 0x05
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xEB
        _emit 0x02
        _emit 0x33
        _emit 0xC0
    }
}
