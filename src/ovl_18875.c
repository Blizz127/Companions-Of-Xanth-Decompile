void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_18875(void)
{
    _asm {
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_1
        _emit 0x52
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xC6
        _emit 0x06
        _emit 0x28
        _emit 0x6D
        _emit 0x00
        _emit 0xC7
        _emit 0x06
        _emit 0x98
        _emit 0x5D
        _emit 0x28
        _emit 0x6D
        _emit 0x8C
        _emit 0x1E
        _emit 0x9A
        _emit 0x5D
        _emit 0xCB
    }
}
