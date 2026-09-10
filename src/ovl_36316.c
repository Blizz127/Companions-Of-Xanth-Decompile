void far helper_0(void);
int far ovl_36316(int a)
{
    _asm {
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x03
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x08
        _emit 0x48
        _emit 0x74
        _emit 0x17
        _emit 0x48
        _emit 0x74
        _emit 0x2E
        _emit 0xEB
        _emit 0x31
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
        _emit 0x8B
        _emit 0xE5
        _emit 0xEB
        _emit 0x1F
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xC6
        _emit 0x06
        _emit 0x02
        _emit 0x03
        _emit 0x01
        _emit 0xEB
        _emit 0x06
        _emit 0x90
        _emit 0xC6
        _emit 0x06
        _emit 0x03
        _emit 0x03
        _emit 0x01
    }
}
