void far helper_0(void);
int far ovl_45663(void)
{
    _asm {
        _emit 0x8E
        _emit 0x06
        call far ptr helper_0
        _emit 0x02
        _emit 0x03
        _emit 0xDB
        _emit 0x03
        _emit 0xDB
        _emit 0x26
        _emit 0x8B
        _emit 0x87
        _emit 0x24
        _emit 0x07
        _emit 0x26
        _emit 0x8B
        _emit 0x97
        _emit 0x26
        _emit 0x07
        _emit 0xCB
    }
}
