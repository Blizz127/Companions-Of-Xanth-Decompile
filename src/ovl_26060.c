void far helper_0(void);
int far ovl_26060(void)
{
    _asm {
        call far ptr helper_0
        _emit 0x02
        _emit 0xCB
    }
}
