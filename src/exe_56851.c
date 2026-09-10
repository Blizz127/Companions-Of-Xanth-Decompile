void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far exe_56851(void)
{
    _asm {
        call far ptr helper_0
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x1F
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x00
        _emit 0x01
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_4
        _emit 0xB8
        _emit 0xBA
        _emit 0x04
        _emit 0x1E
        _emit 0x50
        call far ptr helper_5
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        call far ptr helper_6
        call far ptr helper_7
        _emit 0xCB
    }
}
