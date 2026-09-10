void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_55711(void)
{
    _asm {
        _emit 0xB8
        _emit 0x0B
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0xA0
        _emit 0x0F
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xFF
        _emit 0x06
        _emit 0xAA
        _emit 0x02
        _emit 0x8B
        _emit 0x1E
        _emit 0xAA
        _emit 0x02
        _emit 0x03
        _emit 0xDB
        _emit 0xFF
        _emit 0xB7
        _emit 0x04
        _emit 0x04
        _emit 0xB8
        _emit 0x8B
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x20
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x8E
        _emit 0x06
        _emit 0x3C
        _emit 0x5A
        _emit 0x8B
        _emit 0x1E
        _emit 0xAA
        _emit 0x02
        _emit 0x03
        _emit 0xDB
        _emit 0x03
        _emit 0xDB
        _emit 0x26
        _emit 0xFF
        _emit 0xB7
        _emit 0xAE
        _emit 0x07
        _emit 0x26
        _emit 0xFF
        _emit 0xB7
        _emit 0xAC
        _emit 0x07
        _emit 0xB8
        _emit 0x44
        _emit 0x00
        _emit 0xBA
        _emit 0x00
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xCB
    }
}
