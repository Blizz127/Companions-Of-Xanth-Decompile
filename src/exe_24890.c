void far helper_0(void);
int far exe_24890(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x8B
        _emit 0x5E
        _emit 0x06
        call far ptr helper_0
        _emit 0x8C
        _emit 0xC2
        _emit 0x8B
        _emit 0xC3
    }
}
