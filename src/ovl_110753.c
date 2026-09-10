void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_110753(void)
{
    _asm {
        _emit 0xFF
        _emit 0x06
        _emit 0xA0
        _emit 0x02
        _emit 0xA1
        _emit 0xA0
        _emit 0x02
        _emit 0x48
        _emit 0x74
        _emit 0x0E
        _emit 0x48
        _emit 0x74
        _emit 0x1D
        _emit 0x48
        _emit 0x74
        _emit 0x20
        _emit 0x48
        _emit 0x74
        _emit 0x23
        _emit 0x48
        _emit 0x74
        _emit 0x26
        _emit 0xEB
        _emit 0x5A
        _emit 0xB8
        _emit 0x2C
        _emit 0x00
        _emit 0xBA
        _emit 0x0A
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xEB
        _emit 0x48
        _emit 0xB8
        _emit 0x2D
        _emit 0x00
        _emit 0xEB
        _emit 0xEC
        _emit 0x90
        _emit 0xB8
        _emit 0x2E
        _emit 0x00
        _emit 0xEB
        _emit 0xE6
        _emit 0x90
        _emit 0xB8
        _emit 0x2F
        _emit 0x00
        _emit 0xEB
        _emit 0xE0
        _emit 0x90
        _emit 0xB8
        _emit 0x0B
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x58
        _emit 0x1B
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x03
        _emit 0x5A
        _emit 0x50
        _emit 0xB8
        _emit 0x1A
        _emit 0x01
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x5A
        _emit 0x00
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xEB
        _emit 0x10
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB9
        _emit 0x09
        _emit 0x00
        _emit 0x51
        call far ptr helper_5
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
