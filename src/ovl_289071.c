void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_289071(void)
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
        _emit 0xB8
        _emit 0x17
        _emit 0x00
        _emit 0xBA
        _emit 0x2E
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0xEC
        _emit 0x37
        _emit 0x1E
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x70
        _emit 0x17
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xC7
        _emit 0x06
        _emit 0xA8
        _emit 0x02
        _emit 0x1B
        _emit 0x00
        _emit 0xB8
        _emit 0x5A
        _emit 0x00
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
