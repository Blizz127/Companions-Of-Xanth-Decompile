void far helper_0(void);
int far ovl_36153(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x0E
        _emit 0x2D
        _emit 0x03
        _emit 0x00
        _emit 0x74
        _emit 0x09
        _emit 0x48
        _emit 0x74
        _emit 0x0E
        _emit 0x48
        _emit 0x74
        _emit 0x25
        _emit 0x48
        _emit 0x75
        _emit 0x42
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xEB
        _emit 0x32
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB8
        _emit 0x05
        _emit 0x00
        _emit 0xEB
        _emit 0x18
        _emit 0x90
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB8
        _emit 0x04
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
    }
}
