void far helper_0(void);
void far helper_1(void);
int far ovl_325222(int a)
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
        _emit 0x1F
        _emit 0xEB
        _emit 0x47
        _emit 0x90
        _emit 0xA1
        _emit 0x06
        _emit 0x6A
        _emit 0x2D
        _emit 0x38
        _emit 0x00
        _emit 0x75
        _emit 0x3E
        _emit 0xB8
        _emit 0x04
        _emit 0x00
        _emit 0xBA
        _emit 0x4D
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
        _emit 0x2C
        _emit 0xA1
        _emit 0x06
        _emit 0x6A
        _emit 0x2D
        _emit 0x13
        _emit 0x00
        _emit 0x74
        _emit 0x08
        _emit 0x2D
        _emit 0x32
        _emit 0x00
        _emit 0x74
        _emit 0x09
        _emit 0xEB
        _emit 0x1B
        _emit 0x90
        _emit 0xB8
        _emit 0x03
        _emit 0x00
        _emit 0xEB
        _emit 0xDA
        _emit 0x90
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB8
        _emit 0xF2
        _emit 0x01
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x06
        _emit 0x6A
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xEB
        _emit 0x02
        _emit 0x33
        _emit 0xC0
    }
}
