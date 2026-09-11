void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_100371(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x02
        _emit 0xC4
        _emit 0x5E
        _emit 0x06
        _emit 0x26
        _emit 0x8B
        _emit 0x07
        _emit 0x2B
        _emit 0x06
        _emit 0x4E
        _emit 0x64
        _emit 0x1B
        _emit 0xC9
        _emit 0x23
        _emit 0xC1
        _emit 0x03
        _emit 0x06
        _emit 0x4E
        _emit 0x64
        _emit 0x89
        _emit 0x46
        _emit 0xFE
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x4C
        _emit 0x64
        _emit 0xFF
        _emit 0x36
        _emit 0x4A
        _emit 0x64
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        call far ptr helper_0
        _emit 0x8B
        _emit 0x46
        _emit 0xFE
        _emit 0x2B
        _emit 0xD2
        _emit 0x2B
        _emit 0xDB
        _emit 0x8B
        _emit 0xC8
        _emit 0x01
        _emit 0x0E
        _emit 0x4A
        _emit 0x64
        _emit 0x13
        _emit 0xDA
        _emit 0xB9
        _emit 0x0C
        _emit 0x00
        _emit 0xD3
        _emit 0xE3
        _emit 0x01
        _emit 0x1E
        _emit 0x4C
        _emit 0x64
        _emit 0x8B
        _emit 0xE5
        _emit 0x5D
        _emit 0xCA
        _emit 0x08
        _emit 0x00
    }
}
