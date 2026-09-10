void far helper_0(void);
void far helper_1(void);
int far exe_47499(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x02
        _emit 0x8B
        _emit 0x46
        _emit 0x0C
        _emit 0xF7
        _emit 0x66
        _emit 0x0A
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0xFF
        _emit 0x76
        _emit 0x0E
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x2B
        _emit 0xD2
        _emit 0xF7
        _emit 0x76
        _emit 0x0A
        _emit 0x89
        _emit 0x46
        _emit 0xFE
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x0D
        _emit 0xB8
        _emit 0x00
        _emit 0x09
        _emit 0xB9
        _emit 0xAA
        _emit 0x21
        _emit 0x51
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0x46
        _emit 0xFE
    }
}
