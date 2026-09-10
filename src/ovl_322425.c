void far helper_0(void);
void far helper_1(void);
int far ovl_322425(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x2D
        _emit 0x06
        _emit 0x00
        _emit 0x75
        _emit 0x4F
        _emit 0xA1
        _emit 0x06
        _emit 0x6A
        _emit 0x3D
        _emit 0x45
        _emit 0x00
        _emit 0x74
        _emit 0x41
        _emit 0x77
        _emit 0x45
        _emit 0x2C
        _emit 0x08
        _emit 0x74
        _emit 0x0F
        _emit 0x2C
        _emit 0x0A
        _emit 0x74
        _emit 0x1F
        _emit 0xFE
        _emit 0xC8
        _emit 0x74
        _emit 0x27
        _emit 0x2C
        _emit 0x19
        _emit 0x74
        _emit 0x29
        _emit 0xEB
        _emit 0x33
        _emit 0x90
        _emit 0xB8
        _emit 0x27
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
        _emit 0x20
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0xEB
        _emit 0xEE
        _emit 0x90
        _emit 0xB8
        _emit 0x26
        _emit 0x00
        _emit 0xEB
        _emit 0xDE
        _emit 0x90
        _emit 0xB8
        _emit 0xE1
        _emit 0x3A
        _emit 0x1E
        _emit 0xEB
        _emit 0xDB
        _emit 0xB8
        _emit 0x28
        _emit 0x00
        _emit 0xEB
        _emit 0xD2
        _emit 0x90
        _emit 0x33
        _emit 0xC0
    }
}
