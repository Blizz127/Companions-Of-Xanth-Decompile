void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_94469(void)
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
        _emit 0xB8
        _emit 0x0B
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xA1
        _emit 0x90
        _emit 0x02
        _emit 0x2D
        _emit 0x05
        _emit 0x00
        _emit 0x74
        _emit 0x06
        _emit 0x48
        _emit 0x74
        _emit 0x0D
        _emit 0xEB
        _emit 0x1B
        _emit 0x90
        _emit 0xB8
        _emit 0x03
        _emit 0x5A
        _emit 0x50
        _emit 0xB8
        _emit 0x3F
        _emit 0x01
        _emit 0xEB
        _emit 0x08
        _emit 0x90
        _emit 0xB8
        _emit 0x01
        _emit 0x5A
        _emit 0x50
        _emit 0xB8
        _emit 0xE1
        _emit 0x02
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0xCB
    }
}
