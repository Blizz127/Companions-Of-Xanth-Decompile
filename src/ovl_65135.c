void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_65135(void)
{
    _asm {
        _emit 0xB8
        _emit 0x15
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x56
        _emit 0x02
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x06
        _emit 0xB8
        _emit 0x20
        _emit 0x1E
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        _emit 0xB8
        _emit 0x25
        _emit 0x1E
        _emit 0x1E
        _emit 0x50
        _emit 0xB8
        _emit 0x2A
        _emit 0x1E
        _emit 0x1E
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x04
        _emit 0x6A
        _emit 0xB8
        _emit 0x54
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x52
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x02
        _emit 0x6A
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x52
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x04
        _emit 0x6A
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x4C
        _emit 0x00
        _emit 0xBA
        _emit 0x12
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x14
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
