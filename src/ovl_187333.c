void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_187333(void)
{
    _asm {
        _emit 0xFF
        _emit 0x06
        _emit 0xBC
        _emit 0x02
        _emit 0xA1
        _emit 0xBC
        _emit 0x02
        _emit 0x48
        _emit 0x74
        _emit 0x08
        _emit 0x48
        _emit 0x74
        _emit 0x29
        _emit 0x48
        _emit 0x74
        _emit 0x38
        _emit 0xEB
        _emit 0x64
        _emit 0xB8
        _emit 0xEE
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x12
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x14
        _emit 0x00
        _emit 0xBA
        _emit 0x1F
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xEB
        _emit 0x40
        _emit 0xB8
        _emit 0x15
        _emit 0x00
        _emit 0xBA
        _emit 0x1F
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xEB
        _emit 0x2E
        _emit 0xB8
        _emit 0x16
        _emit 0x00
        _emit 0xBA
        _emit 0x1F
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x88
        _emit 0x13
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xC7
        _emit 0x06
        _emit 0xA8
        _emit 0x02
        _emit 0x17
        _emit 0x00
        _emit 0xB8
        _emit 0x5A
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x83
        _emit 0x3E
        _emit 0xBC
        _emit 0x02
        _emit 0x03
        _emit 0x7D
        _emit 0x10
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x19
        _emit 0x00
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
