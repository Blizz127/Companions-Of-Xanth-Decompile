void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_11315(void)
{
    _asm {
        _emit 0xFF
        _emit 0x00
        _emit 0x00
        _emit 0xFF
        _emit 0xFF
        _emit 0x00
        _emit 0x00
        _emit 0xFF
        _emit 0xFF
        _emit 0x00
        _emit 0x00
        _emit 0xFF
        _emit 0xFF
        _emit 0xB8
        _emit 0x00
        _emit 0x00
        _emit 0xB9
        _emit 0x67
        _emit 0x31
        _emit 0x51
        _emit 0x50
        _emit 0xB8
        _emit 0xD4
        _emit 0x17
        _emit 0x1E
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x48
        _emit 0x3D
        _emit 0x06
        _emit 0x00
        _emit 0x77
        _emit 0x66
        _emit 0x03
        _emit 0xC0
        _emit 0x93
        _emit 0x2E
        _emit 0xFF
        _emit 0xA7
        _emit 0x24
        _emit 0x00
        _emit 0x90
        _emit 0x32
        _emit 0x00
        _emit 0x3A
        _emit 0x00
        _emit 0x54
        _emit 0x00
        _emit 0x60
        _emit 0x00
        _emit 0x6C
        _emit 0x00
        _emit 0x74
        _emit 0x00
        _emit 0x7C
        _emit 0x00
        call far ptr helper_1
        _emit 0xEB
        _emit 0x48
        _emit 0x90
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x10
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xEB
        _emit 0x2D
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_4
        _emit 0xEB
        _emit 0xE4
        _emit 0x90
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_4
        _emit 0xEB
        _emit 0xE4
        _emit 0x90
        _emit 0x9A
        _emit 0xA5
        _emit 0x03
        _emit 0xCB
    }
}
