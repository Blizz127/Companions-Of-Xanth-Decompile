void far helper_0(void);
void far helper_1(void);
int far ovl_26572(void)
{
    _asm {
        _emit 0x80
        _emit 0x3E
        _emit 0xA3
        _emit 0x18
        _emit 0x00
        _emit 0x74
        _emit 0x13
        _emit 0x80
        _emit 0x3E
        _emit 0xA2
        _emit 0x18
        _emit 0x00
        _emit 0x74
        _emit 0x0C
        _emit 0xB8
        _emit 0x03
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x80
        _emit 0x3E
        _emit 0xA2
        _emit 0x18
        _emit 0x00
        _emit 0x74
        _emit 0x0B
        _emit 0xFF
        _emit 0x36
        _emit 0x86
        _emit 0x02
        _emit 0xFF
        _emit 0x36
        _emit 0x84
        _emit 0x02
        _emit 0xEB
        _emit 0x09
        _emit 0x90
        _emit 0xFF
        _emit 0x36
        _emit 0x8A
        _emit 0x02
        _emit 0xFF
        _emit 0x36
        _emit 0x88
        _emit 0x02
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0xFF
        _emit 0xFF
        _emit 0xCB
    }
}
