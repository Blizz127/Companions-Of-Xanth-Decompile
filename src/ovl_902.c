void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_902(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x02
        _emit 0xB8
        _emit 0x0F
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x0D
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x00
        _emit 0x00
        _emit 0xB9
        _emit 0x1C
        _emit 0x31
        _emit 0x51
        _emit 0x50
        _emit 0xB8
        _emit 0x50
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xB8
        _emit 0x30
        _emit 0x00
        _emit 0xB9
        _emit 0x1C
        _emit 0x31
        _emit 0x51
        _emit 0x50
        _emit 0xB8
        _emit 0x5F
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xC7
        _emit 0x46
        _emit 0xFE
        _emit 0x00
        _emit 0x00
        _emit 0x8A
        _emit 0x46
        _emit 0xFE
        _emit 0x8E
        _emit 0x06
        _emit 0x64
        _emit 0x5A
        _emit 0x26
        _emit 0xA2
        _emit 0x51
        _emit 0x6A
        _emit 0x26
        _emit 0xA2
        _emit 0x52
        _emit 0x6A
        _emit 0x26
        _emit 0xA2
        _emit 0x53
        _emit 0x6A
        _emit 0xB8
        _emit 0x24
        _emit 0x6A
        _emit 0x06
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x46
        _emit 0xFE
        _emit 0x83
        _emit 0x7E
        _emit 0xFE
        _emit 0x3F
        _emit 0x7E
        _emit 0xD7
        _emit 0xB8
        _emit 0xEE
        _emit 0x02
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xC7
        _emit 0x46
        _emit 0xFE
        _emit 0x3F
        _emit 0x00
        _emit 0x8A
        _emit 0x46
        _emit 0xFE
        _emit 0x8E
        _emit 0x06
        _emit 0x64
        _emit 0x5A
        _emit 0x26
        _emit 0xA2
        _emit 0x51
        _emit 0x6A
        _emit 0x26
        _emit 0xA2
        _emit 0x52
        _emit 0x6A
        _emit 0x26
        _emit 0xA2
        _emit 0x53
        _emit 0x6A
        _emit 0xB8
        _emit 0x24
        _emit 0x6A
        _emit 0x06
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x4E
        _emit 0xFE
        _emit 0x79
        _emit 0xDB
        call far ptr helper_5
    }
}
