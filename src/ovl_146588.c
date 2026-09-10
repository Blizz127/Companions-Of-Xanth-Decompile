void far helper_0(void);
int far ovl_146588(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x2D
        _emit 0x06
        _emit 0x00
        _emit 0x75
        _emit 0x1D
        _emit 0xA1
        _emit 0x06
        _emit 0x6A
        _emit 0x2D
        _emit 0x13
        _emit 0x00
        _emit 0x75
        _emit 0x15
        _emit 0xB8
        _emit 0x1D
        _emit 0x00
        _emit 0xBA
        _emit 0x13
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
        _emit 0x03
        _emit 0x90
        _emit 0x33
        _emit 0xC0
    }
}
