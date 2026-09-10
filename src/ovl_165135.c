void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_165135(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x2D
        _emit 0x06
        _emit 0x00
        _emit 0x74
        _emit 0x03
        _emit 0xE9
        _emit 0x84
        _emit 0x00
        _emit 0xA1
        _emit 0x06
        _emit 0x6A
        _emit 0x3D
        _emit 0x45
        _emit 0x00
        _emit 0x74
        _emit 0x66
        _emit 0x77
        _emit 0x7A
        _emit 0x2C
        _emit 0x08
        _emit 0x74
        _emit 0x0C
        _emit 0x2C
        _emit 0x0B
        _emit 0x74
        _emit 0x1E
        _emit 0x2C
        _emit 0x07
        _emit 0x74
        _emit 0x4C
        _emit 0x2C
        _emit 0x12
        _emit 0x75
        _emit 0x6A
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB8
        _emit 0xCA
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x06
        _emit 0x6A
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xEB
        _emit 0x58
        _emit 0x90
        _emit 0x90
        _emit 0xB8
        _emit 0x0E
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0xCA
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x05
        _emit 0xB8
        _emit 0xD3
        _emit 0x2B
        _emit 0xEB
        _emit 0x03
        _emit 0xB8
        _emit 0xD8
        _emit 0x2B
        _emit 0x1E
        _emit 0x50
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0xBA
        _emit 0x1A
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_2
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xEB
        _emit 0x25
        _emit 0x90
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0xEB
        _emit 0xED
        _emit 0x90
        _emit 0xFF
        _emit 0x36
        _emit 0x04
        _emit 0x6A
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_4
        _emit 0x8B
        _emit 0xE5
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x03
        _emit 0x00
        _emit 0xEB
        _emit 0xCC
        _emit 0x33
        _emit 0xC0
    }
}
