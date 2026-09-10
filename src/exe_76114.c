void far helper_0(void);
int far exe_76114(int a)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x06
        _emit 0x00
        _emit 0x56
        _emit 0x57
        call far ptr helper_0
        _emit 0x05
        _emit 0x3C
        _emit 0x00
        _emit 0x83
        _emit 0xD2
        _emit 0x00
        _emit 0x89
        _emit 0x46
        _emit 0xFA
        _emit 0x89
        _emit 0x56
        _emit 0xFC
        call far ptr helper_0
        _emit 0x3B
        _emit 0x56
        _emit 0xFC
        _emit 0x7E
        _emit 0x03
        _emit 0xE9
        _emit 0x10
        _emit 0x00
        _emit 0x7D
        _emit 0x03
        _emit 0xE9
        _emit 0x08
        _emit 0x00
        _emit 0x3B
        _emit 0x46
        _emit 0xFA
        _emit 0x72
        _emit 0x03
        _emit 0xE9
        _emit 0x03
        _emit 0x00
        _emit 0xE9
        _emit 0xE3
        _emit 0xFF
        _emit 0x5F
        _emit 0x5E
    }
}
