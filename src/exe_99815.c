void far helper_0(void);
void far helper_1(void);
int far exe_99815(void)
{
    _asm {
        _emit 0xC7
        _emit 0x06
        _emit 0xA0
        _emit 0x4E
        _emit 0x01
        _emit 0x00
        call far ptr helper_0
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xC7
        _emit 0x06
        _emit 0xA0
        _emit 0x4E
        _emit 0x00
        _emit 0x00
        _emit 0xCB
    }
}
