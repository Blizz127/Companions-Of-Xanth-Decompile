void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_321675(int a)
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
        _emit 0x80
        _emit 0x00
        _emit 0xA1
        _emit 0x06
        _emit 0x6A
        _emit 0x3D
        _emit 0x45
        _emit 0x00
        _emit 0x74
        _emit 0x72
        _emit 0x77
        _emit 0x76
        _emit 0x3C
        _emit 0x2C
        _emit 0x74
        _emit 0x16
        _emit 0x77
        _emit 0x0A
        _emit 0x2C
        _emit 0x08
        _emit 0x74
        _emit 0x10
        _emit 0x2C
        _emit 0x0B
        _emit 0x74
        _emit 0x20
        _emit 0xEB
        _emit 0x66
        _emit 0x2C
        _emit 0x34
        _emit 0x74
        _emit 0x20
        _emit 0x2C
        _emit 0x10
        _emit 0x74
        _emit 0x52
        _emit 0xEB
        _emit 0x5C
        _emit 0xB8
        _emit 0x14
        _emit 0x00
        _emit 0xBA
        _emit 0x4B
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xEB
        _emit 0x4A
        _emit 0xB8
        _emit 0x12
        _emit 0x00
        _emit 0xEB
        _emit 0xEA
        _emit 0x90
        _emit 0xB8
        _emit 0x16
        _emit 0x00
        _emit 0xBA
        _emit 0x4B
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        call far ptr helper_1
        _emit 0xB8
        _emit 0xC4
        _emit 0x3A
        _emit 0x1E
        _emit 0x50
        call far ptr helper_2
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x70
        _emit 0x17
        _emit 0x50
        call far ptr helper_3
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0xDE
        _emit 0x01
        _emit 0x50
        call far ptr helper_4
        _emit 0xEB
        _emit 0xBD
        _emit 0xB8
        _emit 0x13
        _emit 0x00
        _emit 0xEB
        _emit 0xAE
        _emit 0x90
        _emit 0xB8
        _emit 0x15
        _emit 0x00
        _emit 0xEB
        _emit 0xA8
        _emit 0x90
        _emit 0x33
        _emit 0xC0
    }
}
