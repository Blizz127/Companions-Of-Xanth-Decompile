void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_68192(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x2D
        _emit 0x06
        _emit 0x00
        _emit 0x75
        _emit 0x5D
        _emit 0xA1
        _emit 0x06
        _emit 0x6A
        _emit 0x3D
        _emit 0x45
        _emit 0x00
        _emit 0x74
        _emit 0x35
        _emit 0x77
        _emit 0x53
        _emit 0x2C
        _emit 0x13
        _emit 0x74
        _emit 0x08
        _emit 0x2C
        _emit 0x19
        _emit 0x74
        _emit 0x04
        _emit 0x2C
        _emit 0x0E
        _emit 0x75
        _emit 0x47
        _emit 0xB8
        _emit 0x11
        _emit 0x00
        _emit 0xBA
        _emit 0x15
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_0
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
        _emit 0xB9
        _emit 0xB1
        _emit 0x80
        _emit 0x51
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xEB
        _emit 0x22
        _emit 0xFF
        _emit 0x36
        _emit 0x04
        _emit 0x6A
        _emit 0xB8
        _emit 0x12
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x8B
        _emit 0xE5
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x12
        _emit 0x00
        _emit 0xBA
        _emit 0x15
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_0
        _emit 0xEB
        _emit 0xD9
        _emit 0x33
        _emit 0xC0
    }
}
