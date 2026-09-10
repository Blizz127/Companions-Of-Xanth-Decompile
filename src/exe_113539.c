void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far exe_113539(void)
{
    _asm {
        call far ptr helper_0
        call far ptr helper_1
        call far ptr helper_2
        call far ptr helper_3
        call far ptr helper_4
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_5
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_6
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_7
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xCB
    }
}
