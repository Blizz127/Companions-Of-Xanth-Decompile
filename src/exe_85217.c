void far helper_0(void);
int far exe_85217(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0xA3
        _emit 0x48
        _emit 0x63
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0xA3
        _emit 0x4A
        _emit 0x63
        _emit 0xC4
        _emit 0x1E
        _emit 0x40
        _emit 0x63
        _emit 0x26
        _emit 0x80
        _emit 0x7F
        _emit 0x03
        _emit 0x00
        _emit 0x75
        _emit 0x1F
        _emit 0x99
        _emit 0x83
        _emit 0xE2
        _emit 0x07
        _emit 0x03
        _emit 0xC2
        _emit 0xB9
        _emit 0x03
        _emit 0x00
        _emit 0xD3
        _emit 0xF8
        _emit 0x40
        _emit 0x50
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x99
        _emit 0x83
        _emit 0xE2
        _emit 0x07
        _emit 0x03
        _emit 0xC2
        _emit 0xD3
        _emit 0xF8
        _emit 0x40
        _emit 0x50
        call far ptr helper_0
    }
}
