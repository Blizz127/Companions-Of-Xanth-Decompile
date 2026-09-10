void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_87983(int a)
{
    _asm {
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0x8B
        _emit 0x46
        _emit 0x0A
        _emit 0x03
        _emit 0x46
        _emit 0x06
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0E
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        _emit 0x50
        call far ptr helper_0
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0x8B
        _emit 0x0E
        _emit 0xFE
        _emit 0x6D
        _emit 0x3B
        _emit 0xC8
        _emit 0x7D
        _emit 0x02
        _emit 0x8B
        _emit 0xC8
        _emit 0x51
        _emit 0x50
        call far ptr helper_1
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0x8B
        _emit 0x46
        _emit 0x0E
        _emit 0x2B
        _emit 0x46
        _emit 0x06
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0E
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
    }
}
