void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_75827(int a)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x06
        _emit 0x00
        _emit 0x56
        _emit 0x57
        call far ptr helper_0
        _emit 0xB8
        _emit 0x20
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x00
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x00
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xC7
        _emit 0x46
        _emit 0xFC
        _emit 0x20
        _emit 0x00
        _emit 0xC7
        _emit 0x46
        _emit 0xFA
        _emit 0x00
        _emit 0x00
        _emit 0xE9
        _emit 0x25
        _emit 0x00
        _emit 0xC4
        _emit 0x5E
        _emit 0x06
        _emit 0x26
        _emit 0x8A
        _emit 0x07
        _emit 0x98
        _emit 0x01
        _emit 0x46
        _emit 0xFC
        _emit 0x8B
        _emit 0x5E
        _emit 0x06
        _emit 0x8E
        _emit 0x46
        _emit 0x08
        _emit 0x83
        _emit 0x46
        _emit 0x06
        _emit 0x01
        _emit 0x26
        _emit 0x8A
        _emit 0x07
        _emit 0x98
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x83
        _emit 0x46
        _emit 0xFA
        _emit 0x01
        _emit 0x83
        _emit 0x7E
        _emit 0xFA
        _emit 0x14
        _emit 0x7D
        _emit 0x03
        _emit 0xE9
        _emit 0xD2
        _emit 0xFF
        _emit 0x8B
        _emit 0x46
        _emit 0xFC
        _emit 0x25
        _emit 0x7F
        _emit 0x00
        _emit 0xB9
        _emit 0x80
        _emit 0x00
        _emit 0x2B
        _emit 0xC8
        _emit 0x8B
        _emit 0xC1
        _emit 0x98
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_2
        call far ptr helper_3
        _emit 0x5F
        _emit 0x5E
    }
}
