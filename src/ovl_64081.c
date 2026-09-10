void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_64081(void)
{
    _asm {
        _emit 0x26
        _emit 0x80
        _emit 0xBF
        _emit 0x66
        _emit 0x00
        _emit 0x05
        _emit 0x74
        _emit 0x2C
        _emit 0xB8
        _emit 0x08
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x04
        _emit 0x6A
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x18
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
        _emit 0x37
        _emit 0x00
        _emit 0xEB
        _emit 0x16
        _emit 0x90
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
        _emit 0x36
        _emit 0x00
        _emit 0xBA
        _emit 0x12
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
