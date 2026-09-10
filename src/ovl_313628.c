void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_313628(int a)
{
    _asm {
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0xB8
        _emit 0x03
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x03
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x06
        _emit 0xB8
        _emit 0x15
        _emit 0x3A
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        _emit 0xB8
        _emit 0x1F
        _emit 0x3A
        _emit 0x1E
        _emit 0x50
        _emit 0xB8
        _emit 0x04
        _emit 0x00
        _emit 0xBA
        _emit 0x49
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_2
    }
}
