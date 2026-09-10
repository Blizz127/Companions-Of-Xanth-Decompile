void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_316878(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x2D
        _emit 0x04
        _emit 0x00
        _emit 0x74
        _emit 0x07
        _emit 0x48
        _emit 0x48
        _emit 0x74
        _emit 0x31
        _emit 0xEB
        _emit 0x7F
        _emit 0x90
        _emit 0xA1
        _emit 0x06
        _emit 0x6A
        _emit 0x2D
        _emit 0x38
        _emit 0x00
        _emit 0x75
        _emit 0x76
        _emit 0xFF
        _emit 0x36
        _emit 0x04
        _emit 0x6A
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x4E
        _emit 0x00
        _emit 0xBA
        _emit 0x49
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
        _emit 0x53
        _emit 0x90
        _emit 0xA1
        _emit 0x06
        _emit 0x6A
        _emit 0x3D
        _emit 0x5C
        _emit 0x00
        _emit 0x74
        _emit 0x42
        _emit 0x77
        _emit 0x46
        _emit 0x3C
        _emit 0x2C
        _emit 0x74
        _emit 0x14
        _emit 0x77
        _emit 0x0A
        _emit 0x2C
        _emit 0x08
        _emit 0x74
        _emit 0x0E
        _emit 0x2C
        _emit 0x0B
        _emit 0x74
        _emit 0x16
        _emit 0xEB
        _emit 0x36
        _emit 0x2C
        _emit 0x44
        _emit 0x74
        _emit 0x26
        _emit 0xFE
        _emit 0xC8
        _emit 0x75
        _emit 0x2E
        _emit 0xFF
        _emit 0x36
        _emit 0x04
        _emit 0x6A
        call far ptr helper_2
        _emit 0xEB
        _emit 0xCB
        _emit 0x90
        _emit 0xB8
        _emit 0x4B
        _emit 0x00
        _emit 0xBA
        _emit 0x49
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        call far ptr helper_3
        _emit 0xEB
        _emit 0xB6
        _emit 0xB8
        _emit 0x4C
        _emit 0x00
        _emit 0xEB
        _emit 0xA5
        _emit 0x90
        _emit 0xB8
        _emit 0x4D
        _emit 0x00
        _emit 0xEB
        _emit 0xE2
        _emit 0x90
        _emit 0x33
        _emit 0xC0
    }
}
