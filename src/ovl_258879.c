void far helper_0(void);
void far helper_1(void);
int far ovl_258879(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0xC7
        _emit 0x46
        _emit 0xFE
        _emit 0x00
        _emit 0x00
        _emit 0xC7
        _emit 0x46
        _emit 0xFC
        _emit 0x98
        _emit 0x34
        _emit 0x8E
        _emit 0x06
        _emit 0x26
        _emit 0x5B
        _emit 0xB1
        _emit 0x04
        _emit 0x8B
        _emit 0x1E
        _emit 0xD0
        _emit 0x02
        _emit 0x8B
        _emit 0xC3
        _emit 0x03
        _emit 0xDB
        _emit 0x03
        _emit 0xDB
        _emit 0x03
        _emit 0xD8
        _emit 0x03
        _emit 0x5E
        _emit 0xFE
        _emit 0xD3
        _emit 0xE3
        _emit 0x26
        _emit 0xFF
        _emit 0xB7
        _emit 0xC2
        _emit 0x05
        _emit 0x8B
        _emit 0x5E
        _emit 0xFC
        _emit 0xFF
        _emit 0x37
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB9
        _emit 0x43
        _emit 0x01
        _emit 0x51
        _emit 0x8B
        _emit 0x5E
        _emit 0xFC
        _emit 0xFF
        _emit 0x37
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xFF
        _emit 0x46
        _emit 0xFE
        _emit 0x83
        _emit 0x46
        _emit 0xFC
        _emit 0x02
        _emit 0x81
        _emit 0x7E
        _emit 0xFC
        _emit 0xA2
        _emit 0x34
        _emit 0x72
        _emit 0xB4
    }
}
