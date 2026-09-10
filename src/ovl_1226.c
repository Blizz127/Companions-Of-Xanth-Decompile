void far helper_0(void);
void far helper_1(void);
int far ovl_1226(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        call far ptr helper_0
        _emit 0x8B
        _emit 0xC8
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x8B
        _emit 0xDA
        _emit 0x99
        _emit 0x03
        _emit 0xC8
        _emit 0x13
        _emit 0xDA
        _emit 0x89
        _emit 0x4E
        _emit 0xFC
        _emit 0x89
        _emit 0x5E
        _emit 0xFE
        call far ptr helper_1
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x11
        call far ptr helper_0
        _emit 0x3B
        _emit 0x56
        _emit 0xFE
        _emit 0x7C
        _emit 0xED
        _emit 0x7F
        _emit 0x05
        _emit 0x3B
        _emit 0x46
        _emit 0xFC
        _emit 0x72
        _emit 0xE6
    }
}
