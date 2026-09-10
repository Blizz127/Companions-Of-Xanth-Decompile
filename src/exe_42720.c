void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_42720(void)
{
    _asm {
        _emit 0xA1
        _emit 0xE8
        _emit 0x69
        _emit 0x48
        _emit 0x48
        _emit 0x74
        _emit 0x0B
        _emit 0x48
        _emit 0x74
        _emit 0x2E
        _emit 0x48
        _emit 0x74
        _emit 0x33
        _emit 0x48
        _emit 0x74
        _emit 0x4A
        _emit 0xEB
        _emit 0x4D
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0x33
        _emit 0xC9
        _emit 0x51
        _emit 0x50
        _emit 0x50
        _emit 0xB8
        _emit 0x50
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x0C
        _emit 0xB8
        _emit 0xF4
        _emit 0x01
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xEB
        _emit 0x27
        call far ptr helper_2
        _emit 0xEB
        _emit 0x20
        _emit 0x90
        _emit 0x83
        _emit 0x3E
        _emit 0x56
        _emit 0x00
        _emit 0x01
        _emit 0x1B
        _emit 0xC0
        _emit 0xF7
        _emit 0xD8
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_4
        _emit 0xEB
        _emit 0x06
        _emit 0x90
        call far ptr helper_5
        call far ptr helper_6
        _emit 0xCB
    }
}
