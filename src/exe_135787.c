void far helper_0(void);
int far exe_135787(void)
{
    _asm {
        _emit 0xE8
        call far ptr helper_0
        _emit 0xCB
    }
}
