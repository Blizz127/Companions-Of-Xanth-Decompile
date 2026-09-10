void far helper_0(void);
int far ovl_9686(int a)
{
    _asm {
        _emit 0xB8
        _emit 0x09
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x1D
        _emit 0xA1
        _emit 0x92
        _emit 0x5D
        _emit 0x39
        _emit 0x46
        _emit 0x08
        _emit 0x7D
        _emit 0x15
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0xA3
        _emit 0x94
        _emit 0x5D
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0xA3
        _emit 0x92
        _emit 0x5D
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x05
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xEB
        _emit 0x02
        _emit 0x33
        _emit 0xC0
    }
}
