void far helper_0(void);
void far helper_1(void);
int far exe_61112(void)
{
    _asm {
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0x50
        _emit 0xB8
        _emit 0x40
        _emit 0x00
        _emit 0xB9
        _emit 0x52
        _emit 0x22
        _emit 0x51
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xCB
    }
}
