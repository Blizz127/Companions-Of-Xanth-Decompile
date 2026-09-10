void far helper_0(void);
void far helper_1(void);
int far ovl_8624(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x06
        _emit 0x8D
        _emit 0x46
        _emit 0xFC
        _emit 0x16
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x8B
        _emit 0x46
        _emit 0xFC
        _emit 0x89
        _emit 0x46
        _emit 0xFA
        _emit 0x48
        _emit 0x75
        _emit 0x03
        _emit 0xFF
        _emit 0x46
        _emit 0xFA
        _emit 0xFF
        _emit 0x76
        _emit 0xFA
        call far ptr helper_1
    }
}
