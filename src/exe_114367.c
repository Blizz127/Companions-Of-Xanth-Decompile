void far helper_0(void);
void far helper_1(void);
int far exe_114367(int a)
{
    _asm {
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x7C
        _emit 0x33
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x08
        _emit 0x7D
        _emit 0x2D
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x8B
        _emit 0x5E
        _emit 0x06
        _emit 0x03
        _emit 0xDB
        _emit 0x89
        _emit 0x87
        _emit 0x10
        _emit 0x68
        _emit 0x8B
        _emit 0x4E
        _emit 0x0A
        _emit 0x89
        _emit 0x8F
        _emit 0x20
        _emit 0x68
        _emit 0x8B
        _emit 0x56
        _emit 0x0C
        _emit 0x89
        _emit 0x97
        _emit 0x30
        _emit 0x68
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        call far ptr helper_1
    }
}
