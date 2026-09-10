void far helper_0(void);
void far helper_1(void);
int far ovl_264284(int a)
{
    _asm {
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x10
        _emit 0x75
        _emit 0x29
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x98
        _emit 0x50
        _emit 0xB8
        _emit 0x54
        _emit 0x35
        _emit 0x1E
        _emit 0x50
        _emit 0xB8
        _emit 0x96
        _emit 0x13
        _emit 0xB9
        _emit 0x20
        _emit 0x34
        _emit 0x51
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x96
        _emit 0x13
        _emit 0xBA
        _emit 0x20
        _emit 0x34
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        _emit 0x33
        _emit 0xC0
        _emit 0x99
    }
}
