void far cli_flag(int a)
{
    _asm {
        cmp word ptr a, 0
        _emit 0x75
        _emit 0x04
        cli
        _emit 0xEB
        _emit 0x02
        _emit 0x90
        sti
    }
}
