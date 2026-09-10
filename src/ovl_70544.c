void far helper_0(void);
int far ovl_70544(int a)
{
    _asm {
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x10
        _emit 0x75
        _emit 0x1D
        _emit 0xB8
        _emit 0x56
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x3D
        _emit 0x10
        _emit 0x01
        _emit 0x75
        _emit 0x05
        _emit 0xB8
        _emit 0xA7
        _emit 0x1E
        _emit 0xEB
        _emit 0x03
        _emit 0xB8
        _emit 0xB0
        _emit 0x1E
        _emit 0x8C
        _emit 0xDA
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        _emit 0x33
        _emit 0xC0
        _emit 0x99
    }
}
