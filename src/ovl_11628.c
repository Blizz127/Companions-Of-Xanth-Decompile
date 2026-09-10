void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
void far helper_9(void);
int far ovl_11628(int a)
{
    _asm {
        _emit 0x57
        _emit 0x56
        call far ptr helper_0
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0x83
        _emit 0x7E
        _emit 0x0A
        _emit 0x01
        _emit 0x1B
        _emit 0xC9
        _emit 0x83
        _emit 0xE1
        _emit 0x01
        _emit 0x83
        _emit 0xC1
        _emit 0x21
        _emit 0x51
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        call far ptr helper_3
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0xFF
        _emit 0xFF
        _emit 0x50
        _emit 0xB9
        _emit 0x0F
        _emit 0x00
        _emit 0x51
        call far ptr helper_5
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x40
        _emit 0x50
        _emit 0x8B
        _emit 0x4E
        _emit 0x06
        _emit 0x83
        _emit 0xC1
        _emit 0x14
        _emit 0x51
        _emit 0x8B
        _emit 0xF0
        _emit 0x8B
        _emit 0xF9
        call far ptr helper_6
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x03
        _emit 0x06
        _emit 0xF8
        _emit 0x69
        _emit 0x40
        _emit 0x50
        _emit 0xB8
        _emit 0xD7
        _emit 0x00
        _emit 0x50
        _emit 0x56
        _emit 0x57
        call far ptr helper_7
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x83
        _emit 0x7E
        _emit 0x0A
        _emit 0x00
        _emit 0x74
        _emit 0x05
        _emit 0xB8
        _emit 0xD5
        _emit 0x17
        _emit 0xEB
        _emit 0x03
        _emit 0xB8
        _emit 0xD8
        _emit 0x17
        _emit 0x1E
        _emit 0x50
        call far ptr helper_8
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0xFF
        _emit 0xFF
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_9
        _emit 0x5E
        _emit 0x5F
    }
}
