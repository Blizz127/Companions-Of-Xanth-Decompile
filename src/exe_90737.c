void far helper_0(void);
void far helper_1(void);
int far exe_90737(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x06
        _emit 0x57
        _emit 0xC7
        _emit 0x06
        _emit 0x3A
        _emit 0x4D
        _emit 0x00
        _emit 0x00
        _emit 0xB8
        _emit 0xFF
        _emit 0xFF
        _emit 0xB9
        _emit 0x08
        _emit 0x00
        _emit 0xBF
        _emit 0x54
        _emit 0x63
        _emit 0x1E
        _emit 0x07
        _emit 0xF3
        _emit 0xAB
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0xB8
        _emit 0x05
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x3C
        _emit 0x4D
        _emit 0x1E
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x0A
        _emit 0xB8
        _emit 0x3C
        _emit 0x4D
        _emit 0x1E
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x5F
    }
}
