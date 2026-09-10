void far helper_0(void);
void far helper_1(void);
int far ovl_82047(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x2D
        _emit 0x06
        _emit 0x00
        _emit 0x75
        _emit 0x41
        _emit 0xA1
        _emit 0x06
        _emit 0x6A
        _emit 0x3D
        _emit 0x45
        _emit 0x00
        _emit 0x74
        _emit 0x33
        _emit 0x77
        _emit 0x37
        _emit 0x2C
        _emit 0x13
        _emit 0x74
        _emit 0x0B
        _emit 0x2C
        _emit 0x19
        _emit 0x74
        _emit 0x23
        _emit 0x2C
        _emit 0x18
        _emit 0x74
        _emit 0x1F
        _emit 0xEB
        _emit 0x29
        _emit 0x90
        call far ptr helper_0
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x1A
        _emit 0x00
        _emit 0xBA
        _emit 0x04
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
        _emit 0x0F
        _emit 0x90
        _emit 0xB8
        _emit 0x1C
        _emit 0x00
        _emit 0xEB
        _emit 0xE9
        _emit 0x90
        _emit 0xB8
        _emit 0x1B
        _emit 0x00
        _emit 0xEB
        _emit 0xE3
        _emit 0x90
        _emit 0x33
        _emit 0xC0
    }
}
