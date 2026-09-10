
int near ovl_170629(void)
{
    _asm {
        _emit 0x8B
        _emit 0x1E
        _emit 0xEA
        _emit 0x02
        _emit 0x8B
        _emit 0xC3
    }
}
