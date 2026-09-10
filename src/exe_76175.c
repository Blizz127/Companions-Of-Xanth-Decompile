void far helper_0(void);
void far helper_1(void);
int far exe_76175(int a)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        _emit 0xA1
        _emit 0x6E
        _emit 0x41
        _emit 0x25
        _emit 0x80
        _emit 0x00
        _emit 0x3D
        _emit 0x00
        _emit 0x00
        _emit 0x74
        _emit 0x03
        _emit 0xE9
        _emit 0x2D
        _emit 0x00
        _emit 0xB8
        _emit 0x08
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xA3
        _emit 0xF8
        _emit 0x6D
        _emit 0x89
        _emit 0x16
        _emit 0xFA
        _emit 0x6D
        _emit 0xB8
        _emit 0xB3
        _emit 0x9F
        _emit 0xBA
        _emit 0xA7
        _emit 0x08
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x08
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x81
        _emit 0x0E
        _emit 0x6E
        _emit 0x41
        _emit 0x80
        _emit 0x00
        _emit 0x5F
        _emit 0x5E
    }
}
