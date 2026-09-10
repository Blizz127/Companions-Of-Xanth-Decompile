void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far exe_98020(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x08
        _emit 0x83
        _emit 0x3E
        _emit 0x9E
        _emit 0x4E
        _emit 0x00
        _emit 0x74
        _emit 0x03
        _emit 0xE9
        _emit 0xBB
        _emit 0x00
        _emit 0xB8
        _emit 0x33
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x8E
        _emit 0xC2
        _emit 0x8B
        _emit 0xD8
        _emit 0x89
        _emit 0x46
        _emit 0xFC
        _emit 0x8C
        _emit 0x46
        _emit 0xFE
        _emit 0x26
        _emit 0x8A
        _emit 0x07
        _emit 0x88
        _emit 0x46
        _emit 0xF8
        _emit 0x8B
        _emit 0xCA
        _emit 0x0B
        _emit 0xCB
        _emit 0x74
        _emit 0x04
        _emit 0x3C
        _emit 0xCF
        _emit 0x75
        _emit 0x1C
        _emit 0xB8
        _emit 0xA2
        _emit 0x4E
        _emit 0x1E
        _emit 0x50
        _emit 0xB8
        _emit 0x38
        _emit 0x54
        _emit 0x1E
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        call far ptr helper_2
        call far ptr helper_3
        _emit 0xB8
        _emit 0x20
        _emit 0x00
        _emit 0xCD
        _emit 0x33
        _emit 0xB8
        _emit 0x00
        _emit 0x00
        _emit 0xCD
        _emit 0x33
        _emit 0x89
        _emit 0x46
        _emit 0xFA
        _emit 0x83
        _emit 0x7E
        _emit 0xFA
        _emit 0xFF
        _emit 0x74
        _emit 0x26
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_4
        _emit 0xB8
        _emit 0xC1
        _emit 0x4E
        _emit 0x1E
        _emit 0x50
        _emit 0xB8
        _emit 0x38
        _emit 0x54
        _emit 0x1E
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_5
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xC7
        _emit 0x06
        _emit 0x9E
        _emit 0x4E
        _emit 0x80
        _emit 0x00
        _emit 0xB8
        _emit 0x00
        _emit 0x01
        _emit 0x99
        _emit 0x52
        _emit 0x50
        call far ptr helper_6
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xA3
        _emit 0x3C
        _emit 0x64
        _emit 0x89
        _emit 0x16
        _emit 0x3E
        _emit 0x64
        _emit 0xB8
        _emit 0x00
        _emit 0x01
        _emit 0x99
        _emit 0x52
        _emit 0x50
        call far ptr helper_6
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xA3
        _emit 0x40
        _emit 0x64
        _emit 0x89
        _emit 0x16
        _emit 0x42
        _emit 0x64
        call far ptr helper_7
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x74
        _emit 0x05
        call far ptr helper_8
    }
}
