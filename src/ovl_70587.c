void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_70587(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        call far ptr helper_0
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x3E
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x50
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0xB8
        _emit 0x06
        _emit 0x00
        _emit 0x03
        _emit 0xE0
        _emit 0x50
        _emit 0xB8
        _emit 0x50
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x83
        _emit 0x3E
        _emit 0x56
        _emit 0x02
        _emit 0x33
        _emit 0x75
        _emit 0x23
        _emit 0xB8
        _emit 0x0E
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x34
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x0F
        _emit 0xB8
        _emit 0x40
        _emit 0x00
        _emit 0xBA
        _emit 0x15
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_4
        _emit 0xEB
        _emit 0x33
        _emit 0x83
        _emit 0x3E
        _emit 0x56
        _emit 0x02
        _emit 0x33
        _emit 0x75
        _emit 0x05
        _emit 0x33
        _emit 0xC0
        _emit 0x99
        _emit 0xEB
        _emit 0x05
        _emit 0xB8
        _emit 0xB7
        _emit 0x1E
        _emit 0x8C
        _emit 0xDA
        _emit 0x89
        _emit 0x46
        _emit 0xFC
        _emit 0x89
        _emit 0x56
        _emit 0xFE
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x41
        _emit 0x00
        _emit 0xBA
        _emit 0x15
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xB8
        _emit 0xC5
        _emit 0x1E
        _emit 0x1E
        _emit 0x50
        call far ptr helper_5
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xA2
        _emit 0x22
        _emit 0x03
    }
}
