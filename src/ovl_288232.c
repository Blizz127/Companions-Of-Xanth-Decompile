void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_288232(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x2D
        _emit 0x06
        _emit 0x00
        _emit 0x75
        _emit 0x7F
        _emit 0xA1
        _emit 0x06
        _emit 0x6A
        _emit 0x3D
        _emit 0x45
        _emit 0x00
        _emit 0x74
        _emit 0x5F
        _emit 0x77
        _emit 0x75
        _emit 0x2C
        _emit 0x07
        _emit 0x74
        _emit 0x11
        _emit 0xFE
        _emit 0xC8
        _emit 0x74
        _emit 0x33
        _emit 0x2C
        _emit 0x0B
        _emit 0x74
        _emit 0x3B
        _emit 0x2C
        _emit 0x19
        _emit 0x74
        _emit 0x2B
        _emit 0xEB
        _emit 0x63
        _emit 0x90
        _emit 0x90
        _emit 0x90
        _emit 0xFF
        _emit 0x36
        _emit 0x04
        _emit 0x6A
        _emit 0xB8
        _emit 0x12
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x0B
        _emit 0x00
        _emit 0xBA
        _emit 0x2E
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xEB
        _emit 0x3D
        _emit 0x90
        _emit 0xFF
        _emit 0x36
        _emit 0x04
        _emit 0x6A
        call far ptr helper_2
        _emit 0xEB
        _emit 0xED
        _emit 0x90
        _emit 0xFF
        _emit 0x36
        _emit 0x04
        _emit 0x6A
        _emit 0xB8
        _emit 0x12
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x09
        _emit 0x00
        _emit 0xEB
        _emit 0xCC
        _emit 0xFF
        _emit 0x36
        _emit 0x04
        _emit 0x6A
        _emit 0xB8
        _emit 0x12
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0xEB
        _emit 0xB5
        _emit 0x90
        _emit 0x33
        _emit 0xC0
    }
}
