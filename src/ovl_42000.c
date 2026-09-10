
int far ovl_42000(void)
{
    _asm {
        _emit 0xB4
        _emit 0x09
        _emit 0xCB
        _emit 0x30
        _emit 0xD6
        _emit 0x09
        _emit 0xCB
    }
}
