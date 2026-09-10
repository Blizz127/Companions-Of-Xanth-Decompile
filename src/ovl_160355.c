void far helper_0(void);
void far helper_1(void);
int far ovl_160355(int a)
{
    _asm {
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x10
        _emit 0x75
        _emit 0x31
        _emit 0x80
        _emit 0x3E
        _emit 0x01
        _emit 0x03
        _emit 0x00
        _emit 0x74
        _emit 0x16
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x91
        _emit 0x2B
        _emit 0x8C
        _emit 0xDA
        _emit 0xEB
        _emit 0x18
        _emit 0x90
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x9E
        _emit 0x2B
        _emit 0xEB
        _emit 0xE8
        _emit 0x90
        _emit 0x33
        _emit 0xC0
        _emit 0x99
    }
}
