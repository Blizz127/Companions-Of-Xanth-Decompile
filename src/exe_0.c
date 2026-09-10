void far helper_0(void);
int far exe_0(void)
{
    _asm {
        _emit 0x55
        call far ptr helper_0
        _emit 0x5D
        _emit 0xCB
    }
}
