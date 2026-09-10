void far helper_0(void);
void far helper_1(void);
int far ovl_9594(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x08
        _emit 0xC7
        _emit 0x46
        _emit 0xFE
        _emit 0x00
        _emit 0x00
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x89
        _emit 0x46
        _emit 0xFC
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x35
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x8B
        _emit 0xC8
        _emit 0x03
        _emit 0xC0
        _emit 0x03
        _emit 0xC1
        _emit 0x03
        _emit 0xC0
        _emit 0x05
        _emit 0x66
        _emit 0x00
        _emit 0xB9
        _emit 0xA1
        _emit 0x23
        _emit 0x89
        _emit 0x46
        _emit 0xF8
        _emit 0x89
        _emit 0x4E
        _emit 0xFA
        _emit 0xC4
        _emit 0x5E
        _emit 0xF8
        _emit 0x26
        _emit 0x80
        _emit 0x3F
        _emit 0x01
        _emit 0x74
        _emit 0x03
        _emit 0xFF
        _emit 0x46
        _emit 0xFE
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x89
        _emit 0x46
        _emit 0xFC
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0xE2
        _emit 0x8B
        _emit 0x46
        _emit 0xFE
    }
}
