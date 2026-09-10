void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_14576(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x7C
        _emit 0x80
        _emit 0x3E
        call far ptr helper_0
        _emit 0xB8
        _emit 0x6A
        _emit 0x02
        _emit 0x1E
        _emit 0x50
        _emit 0xB8
        _emit 0x48
        _emit 0x00
        _emit 0xB9
        _emit 0xC4
        _emit 0x2E
        _emit 0x51
        _emit 0x50
        _emit 0xB8
        _emit 0xA4
        _emit 0x18
        _emit 0x1E
        _emit 0x50
        _emit 0x8D
        _emit 0x46
        _emit 0x84
        _emit 0x16
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x10
        _emit 0x8D
        _emit 0x46
        _emit 0xD4
        _emit 0x16
        _emit 0x50
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0x8D
        _emit 0x4E
        _emit 0x84
        _emit 0x16
        _emit 0x51
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x0A
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x1B
        _emit 0x50
        _emit 0x50
        _emit 0xB8
        _emit 0xAF
        _emit 0x18
        _emit 0x1E
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x48
        _emit 0x75
        _emit 0x09
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_4
        _emit 0xC6
        _emit 0x06
        _emit 0x9A
        _emit 0x18
        _emit 0x00
    }
}
