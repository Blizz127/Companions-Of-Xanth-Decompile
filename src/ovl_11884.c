void far helper_0(void);
int far ovl_11884(void)
{
    _asm {
        _emit 0x83
        _emit 0x3E
        _emit 0x96
        _emit 0x41
        _emit 0x00
        _emit 0x74
        _emit 0x19
        _emit 0xF6
        _emit 0x06
        _emit 0x6E
        _emit 0x41
        _emit 0x08
        _emit 0x75
        _emit 0x08
        _emit 0x80
        _emit 0x0E
        _emit 0x6E
        _emit 0x41
        _emit 0x08
        _emit 0xEB
        _emit 0x0B
        _emit 0x90
        call far ptr helper_0
        _emit 0x80
        _emit 0x26
        _emit 0x6E
        _emit 0x41
        _emit 0xF7
        _emit 0xCB
    }
}
