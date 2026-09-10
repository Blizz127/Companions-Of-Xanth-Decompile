void far helper_0(void);
int far ovl_80879(void)
{
    _asm {
        _emit 0xFF
        _emit 0x00
        _emit 0x00
        _emit 0xFF
        _emit 0xFF
        _emit 0x00
        _emit 0x00
        _emit 0xFF
        _emit 0xFF
        _emit 0x00
        _emit 0x00
        _emit 0xFF
        _emit 0xFF
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0x00
        call far ptr helper_0
        _emit 0xB9
        _emit 0x26
        _emit 0x00
        _emit 0x2B
        _emit 0xD2
        _emit 0xF7
        _emit 0xF1
        _emit 0x8B
        _emit 0xDA
        _emit 0x03
        _emit 0xDA
        _emit 0x03
        _emit 0xDB
        _emit 0x8E
        _emit 0x06
        _emit 0xBC
        _emit 0x5A
        _emit 0x26
        _emit 0x8B
        _emit 0x87
        _emit 0x00
        _emit 0x00
        _emit 0x26
        _emit 0x8B
        _emit 0x97
        _emit 0x02
        _emit 0x00
        _emit 0xCB
    }
}
