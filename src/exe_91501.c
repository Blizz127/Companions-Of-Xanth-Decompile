void far helper_0(void);
int far exe_91501(int a)
{
    _asm {
        _emit 0x83
        _emit 0x3E
        _emit 0x38
        _emit 0x4D
        _emit 0x00
        _emit 0x7C
        _emit 0x46
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x7E
        _emit 0x14
        _emit 0xFF
        _emit 0x06
        _emit 0x38
        _emit 0x4D
        _emit 0x83
        _emit 0x3E
        _emit 0x38
        _emit 0x4D
        _emit 0x08
        _emit 0x75
        _emit 0x15
        _emit 0xC7
        _emit 0x06
        _emit 0x38
        _emit 0x4D
        _emit 0x00
        _emit 0x00
        _emit 0xEB
        _emit 0x0D
        _emit 0x90
        _emit 0xFF
        _emit 0x0E
        _emit 0x38
        _emit 0x4D
        _emit 0x79
        _emit 0x06
        _emit 0xC7
        _emit 0x06
        _emit 0x38
        _emit 0x4D
        _emit 0x07
        _emit 0x00
        _emit 0x8B
        _emit 0x1E
        _emit 0x38
        _emit 0x4D
        _emit 0x03
        _emit 0xDB
        _emit 0x83
        _emit 0xBF
        _emit 0x54
        _emit 0x63
        _emit 0x00
        _emit 0x7C
        _emit 0xCD
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
    }
}
