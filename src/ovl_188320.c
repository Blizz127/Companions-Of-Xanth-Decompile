void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_188320(void)
{
    _asm {
        call far ptr helper_0
        _emit 0xB9
        _emit 0x05
        _emit 0x00
        _emit 0x2B
        _emit 0xD2
        _emit 0xF7
        _emit 0xF1
        _emit 0x8B
        _emit 0xDA
        _emit 0x03
        _emit 0xDA
        _emit 0x03
        _emit 0xDB
        _emit 0x8E
        _emit 0x06
        _emit 0xD8
        _emit 0x5A
        _emit 0x26
        _emit 0xFF
        _emit 0xB7
        _emit 0x6E
        _emit 0x00
        _emit 0x26
        _emit 0xFF
        _emit 0xB7
        _emit 0x6C
        _emit 0x00
        _emit 0xB8
        _emit 0x2E
        _emit 0x00
        _emit 0xBA
        _emit 0x1F
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        call far ptr helper_0
        _emit 0xB9
        _emit 0x03
        _emit 0x00
        _emit 0x99
        _emit 0xF7
        _emit 0xF9
        _emit 0x42
        _emit 0x52
        _emit 0xB8
        _emit 0x2C
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
