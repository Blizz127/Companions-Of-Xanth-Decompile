void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_4455(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        call far ptr helper_0
        _emit 0xB8
        _emit 0x20
        _emit 0x00
        _emit 0xB9
        _emit 0x99
        _emit 0x21
        _emit 0x51
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        call far ptr helper_2
        _emit 0xC7
        _emit 0x06
        _emit 0x84
        _emit 0x5D
        _emit 0x8C
        _emit 0x00
        call far ptr helper_3
        call far ptr helper_4
        _emit 0x05
        _emit 0xB8
        _emit 0x0B
        _emit 0x83
        _emit 0xD2
        _emit 0x00
        _emit 0x89
        _emit 0x46
        _emit 0xFC
        _emit 0x89
        _emit 0x56
        _emit 0xFE
        call far ptr helper_4
        _emit 0x3B
        _emit 0x56
        _emit 0xFE
        _emit 0x7F
        _emit 0x10
        _emit 0x7C
        _emit 0x05
        _emit 0x3B
        _emit 0x46
        _emit 0xFC
        _emit 0x73
        _emit 0x09
        call far ptr helper_5
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0xE6
        _emit 0xB8
        _emit 0x21
        _emit 0x05
        _emit 0xBA
        _emit 0xCB
        _emit 0x30
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x2D
        _emit 0x05
        _emit 0x50
        call far ptr helper_6
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        call far ptr helper_5
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0xF7
        call far ptr helper_7
    }
}
