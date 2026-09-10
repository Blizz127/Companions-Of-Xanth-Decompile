void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_142516(void)
{
    _asm {
        _emit 0xB8
        _emit 0xA7
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x12
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x94
        _emit 0x29
        _emit 0x1E
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xFF
        _emit 0x06
        _emit 0x92
        _emit 0x29
        _emit 0xA1
        _emit 0x92
        _emit 0x29
        _emit 0x48
        _emit 0x74
        _emit 0x09
        _emit 0x48
        _emit 0x74
        _emit 0x1C
        _emit 0x48
        _emit 0x74
        _emit 0x2F
        _emit 0xEB
        _emit 0x50
        _emit 0x90
        _emit 0xB8
        _emit 0x26
        _emit 0x01
        _emit 0x50
        _emit 0xB8
        _emit 0xA7
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x52
        _emit 0x00
        _emit 0xEB
        _emit 0x2D
        _emit 0x90
        _emit 0xB8
        _emit 0x27
        _emit 0x01
        _emit 0x50
        _emit 0xB8
        _emit 0xA7
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x53
        _emit 0x00
        _emit 0xEB
        _emit 0x17
        _emit 0x90
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB8
        _emit 0x9D
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0xA7
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xB8
        _emit 0x54
        _emit 0x00
        _emit 0xBA
        _emit 0x10
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x83
        _emit 0x3E
        _emit 0x92
        _emit 0x29
        _emit 0x03
        _emit 0x7D
        _emit 0x12
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x0E
        _emit 0x00
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xEB
        _emit 0x06
        _emit 0xC7
        _emit 0x06
        _emit 0x92
        _emit 0x29
        _emit 0x00
        _emit 0x00
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
