void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_110357(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0xB8
        _emit 0x14
        _emit 0x00
        _emit 0xF7
        _emit 0x6E
        _emit 0x08
        _emit 0x8B
        _emit 0x5E
        _emit 0x06
        _emit 0x03
        _emit 0xDB
        _emit 0x03
        _emit 0xDB
        _emit 0xC4
        _emit 0x9F
        _emit 0xC2
        _emit 0x67
        _emit 0x03
        _emit 0xD8
        _emit 0x89
        _emit 0x5E
        _emit 0xFC
        _emit 0x8C
        _emit 0x46
        _emit 0xFE
        _emit 0x26
        _emit 0x80
        _emit 0x3F
        _emit 0x05
        _emit 0x75
        _emit 0x57
        _emit 0x26
        _emit 0xC4
        _emit 0x5F
        _emit 0x0A
        _emit 0x26
        _emit 0x80
        _emit 0x3F
        _emit 0x00
        _emit 0x74
        _emit 0x4D
        _emit 0xC4
        _emit 0x5E
        _emit 0xFC
        _emit 0x26
        _emit 0x80
        _emit 0x4F
        _emit 0x01
        _emit 0x80
        call far ptr helper_0
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xC4
        _emit 0x5E
        _emit 0xFC
        _emit 0x26
        _emit 0x8B
        _emit 0x47
        _emit 0x08
        _emit 0x2D
        _emit 0x02
        _emit 0x00
        _emit 0x50
        _emit 0x26
        _emit 0x8B
        _emit 0x47
        _emit 0x06
        _emit 0x2D
        _emit 0x03
        _emit 0x00
        _emit 0x50
        _emit 0x26
        _emit 0x8B
        _emit 0x47
        _emit 0x04
        _emit 0x05
        _emit 0x02
        _emit 0x00
        _emit 0x50
        _emit 0x26
        _emit 0x8B
        _emit 0x47
        _emit 0x02
        _emit 0x05
        _emit 0x03
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x82
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x0A
        call far ptr helper_3
    }
}
