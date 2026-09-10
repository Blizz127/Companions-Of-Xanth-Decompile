void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_61145(void)
{
    _asm {
        _emit 0xB8
        _emit 0x20
        _emit 0x00
        _emit 0xB9
        _emit 0x99
        _emit 0x21
        _emit 0x51
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        call far ptr helper_1
        call far ptr helper_2
        _emit 0xB8
        _emit 0x10
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xCB
    }
}
