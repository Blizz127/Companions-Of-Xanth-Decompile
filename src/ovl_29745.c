void far helper_0(void);
void far helper_1(void);
int far ovl_29745(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x3D
        _emit 0x05
        _emit 0x00
        _emit 0x77
        _emit 0x7A
        _emit 0x03
        _emit 0xC0
        _emit 0x93
        _emit 0x2E
        _emit 0xFF
        _emit 0xA7
        _emit 0x15
        _emit 0x01
        _emit 0x90
        _emit 0x21
        _emit 0x01
        _emit 0x33
        _emit 0x01
        _emit 0x43
        _emit 0x01
        _emit 0x33
        _emit 0x01
        _emit 0x81
        _emit 0x01
        _emit 0x21
        _emit 0x01
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x0D
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xEB
        _emit 0x54
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
        call far ptr helper_1
        _emit 0xEB
        _emit 0xEB
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB9
        _emit 0x03
        _emit 0x00
        _emit 0x51
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB9
        _emit 0x04
        _emit 0x00
        _emit 0x51
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x05
        _emit 0x00
        _emit 0x50
        _emit 0xEB
        _emit 0xB8
        _emit 0xC6
        _emit 0x06
        _emit 0xF5
        _emit 0x02
        _emit 0x01
    }
}
