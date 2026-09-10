void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_74370(int a)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x8B
        _emit 0x56
        _emit 0x08
        _emit 0xA3
        _emit 0xF4
        _emit 0x6D
        _emit 0x89
        _emit 0x16
        _emit 0xF6
        _emit 0x6D
        _emit 0x83
        _emit 0x3E
        _emit 0xF4
        _emit 0x6D
        _emit 0x00
        _emit 0x74
        _emit 0x03
        _emit 0xE9
        _emit 0x10
        _emit 0x00
        _emit 0x83
        _emit 0x3E
        _emit 0xF6
        _emit 0x6D
        _emit 0x00
        _emit 0x74
        _emit 0x03
        _emit 0xE9
        _emit 0x06
        _emit 0x00
        _emit 0xB8
        _emit 0x00
        _emit 0x00
        _emit 0xE9
        _emit 0x4D
        _emit 0x00
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xC4
        _emit 0x1E
        _emit 0xF4
        _emit 0x6D
        _emit 0x26
        _emit 0xFF
        _emit 0x77
        _emit 0x02
        _emit 0x26
        _emit 0xFF
        _emit 0x37
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x3D
        _emit 0x00
        _emit 0x00
        _emit 0x74
        _emit 0x03
        _emit 0xE9
        _emit 0x06
        _emit 0x00
        _emit 0xB8
        _emit 0x00
        _emit 0x00
        _emit 0xE9
        _emit 0x1E
        _emit 0x00
        call far ptr helper_2
        _emit 0x3D
        _emit 0x00
        _emit 0x00
        _emit 0x74
        _emit 0x03
        _emit 0xE9
        _emit 0x06
        _emit 0x00
        _emit 0xB8
        _emit 0x00
        _emit 0x00
        _emit 0xE9
        _emit 0x0B
        _emit 0x00
        call far ptr helper_3
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xE9
        _emit 0x00
        _emit 0x00
        _emit 0x5F
        _emit 0x5E
    }
}
