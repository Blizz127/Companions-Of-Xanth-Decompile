void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_91103(void)
{
    _asm {
        _emit 0xC7
        _emit 0x06
        _emit 0x2E
        _emit 0x22
        _emit 0x01
        _emit 0x00
        _emit 0x83
        _emit 0x3E
        _emit 0x56
        _emit 0x02
        _emit 0x40
        _emit 0x74
        _emit 0x05
        _emit 0xB8
        _emit 0x6E
        _emit 0x00
        _emit 0xEB
        _emit 0x03
        _emit 0xB8
        _emit 0x6F
        _emit 0x00
        _emit 0xBA
        _emit 0x05
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x06
        _emit 0x30
        _emit 0x22
        _emit 0x83
        _emit 0x3E
        _emit 0x30
        _emit 0x22
        _emit 0x06
        _emit 0x73
        _emit 0x1F
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x03
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x2E
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xEB
        _emit 0x2A
        _emit 0x90
        _emit 0xC7
        _emit 0x06
        _emit 0x30
        _emit 0x22
        _emit 0x00
        _emit 0x00
        _emit 0xC7
        _emit 0x06
        _emit 0x2E
        _emit 0x22
        _emit 0x00
        _emit 0x00
        _emit 0xB8
        _emit 0x0C
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x03
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x39
        _emit 0x23
        _emit 0x1E
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x48
        _emit 0x23
        _emit 0x1E
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
