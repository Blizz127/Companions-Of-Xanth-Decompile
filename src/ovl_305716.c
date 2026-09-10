void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_305716(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x3D
        _emit 0x0E
        _emit 0x00
        _emit 0x74
        _emit 0x37
        _emit 0x77
        _emit 0x45
        _emit 0x2C
        _emit 0x08
        _emit 0x74
        _emit 0x0B
        _emit 0xFE
        _emit 0xC8
        _emit 0x7C
        _emit 0x3D
        _emit 0x2C
        _emit 0x02
        _emit 0x7E
        _emit 0x23
        _emit 0xEB
        _emit 0x37
        _emit 0x90
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0xAA
        _emit 0x01
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x09
        _emit 0x00
        _emit 0xBA
        _emit 0x2F
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xEB
        _emit 0x16
        _emit 0xB8
        _emit 0x08
        _emit 0x00
        _emit 0xEB
        _emit 0xED
        _emit 0x90
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x0F
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x33
        _emit 0xC0
    }
}
