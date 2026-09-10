void far helper_0(void);
int far ovl_11449(void)
{
    _asm {
        _emit 0xEB
        _emit 0x06
        _emit 0x90
        call far ptr helper_0
        _emit 0xCB
    }
}
