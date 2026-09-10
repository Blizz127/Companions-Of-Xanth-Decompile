void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_320331(void)
{
    _asm {
        _emit 0xB8
        _emit 0x32
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x06
        _emit 0xB8
        _emit 0xAD
        _emit 0x3A
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        _emit 0xB8
        _emit 0xB8
        _emit 0x3A
        _emit 0x1E
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        call far ptr helper_2
        _emit 0xB9
        _emit 0x04
        _emit 0x00
        _emit 0x99
        _emit 0xF7
        _emit 0xF9
        _emit 0x83
        _emit 0xC2
        _emit 0x02
        _emit 0x52
        _emit 0xB8
        _emit 0x29
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0xCB
    }
}
