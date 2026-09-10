char g;
int far if15_198506(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x74
        _emit 0x0D
        cmp byte ptr g, 1
        cmc
        sbb ax, ax
        and ax, 105h
        _emit 0xEB
        _emit 0x0D
        cmp byte ptr g, 1
        sbb ax, ax
        and ax, 0FEFAh
        add ax, 105h
    }
}
