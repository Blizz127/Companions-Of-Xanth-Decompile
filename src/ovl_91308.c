void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_91308(void)
{
    _asm {
        call far ptr helper_0
        _emit 0xB8
        _emit 0x72
        _emit 0x00
        _emit 0xBA
        _emit 0x05
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_3
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
