void far helper_0(void);
int far ovl_241875(void)
{
    _asm {
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x74
        _emit 0x00
        _emit 0xB9
        _emit 0x8E
        _emit 0x32
        _emit 0x51
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xCB
    }
}
