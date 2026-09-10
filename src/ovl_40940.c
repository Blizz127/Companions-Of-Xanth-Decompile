void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_40940(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x2D
        _emit 0x03
        _emit 0x00
        _emit 0x74
        _emit 0x0B
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0xEB
        _emit 0x46
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB9
        _emit 0xBD
        _emit 0x00
        _emit 0x51
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0xBD
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x32
        _emit 0xC0
        _emit 0xA2
        _emit 0x12
        _emit 0x6A
        _emit 0xA2
        _emit 0x13
        _emit 0x6A
        _emit 0xA2
        _emit 0x14
        _emit 0x6A
        _emit 0xA2
        _emit 0x15
        _emit 0x6A
        _emit 0xA2
        _emit 0x16
        _emit 0x6A
        _emit 0xA2
        _emit 0x17
        _emit 0x6A
        _emit 0xA2
        _emit 0x18
        _emit 0x6A
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x08
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x26
        _emit 0x80
        _emit 0x50
        call far ptr helper_2
    }
}
