void far helper_0(void);
void far helper_1(void);
int far exe_100996(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x02
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xA3
        _emit 0x50
        _emit 0x64
        _emit 0x89
        _emit 0x16
        _emit 0x52
        _emit 0x64
        _emit 0x8B
        _emit 0x46
        _emit 0x0A
        _emit 0xA3
        _emit 0x54
        _emit 0x64
        _emit 0xA3
        _emit 0x56
        _emit 0x64
        _emit 0x2D
        _emit 0x40
        _emit 0x01
        _emit 0xF7
        _emit 0xD8
        _emit 0xA3
        _emit 0x58
        _emit 0x64
        _emit 0xB8
        _emit 0x85
        _emit 0xFD
        _emit 0xBA
        _emit 0xA7
        _emit 0x08
        _emit 0x52
        _emit 0x50
        _emit 0x83
        _emit 0x7E
        _emit 0x0C
        _emit 0x00
        _emit 0x74
        _emit 0x08
        _emit 0xB8
        _emit 0xCA
        _emit 0xFE
        _emit 0xBA
        _emit 0xA7
        _emit 0x08
        _emit 0xEB
        _emit 0x06
        _emit 0xB8
        _emit 0x2D
        _emit 0xFE
        _emit 0xBA
        _emit 0xA7
        _emit 0x08
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x96
        _emit 0x15
        _emit 0xB9
        _emit 0x20
        _emit 0x34
        _emit 0x51
        _emit 0x50
        call far ptr helper_1
    }
}
