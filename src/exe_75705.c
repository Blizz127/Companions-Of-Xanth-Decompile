void far helper1(void);
void far helper2(void);
void far exe_75705(void)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        mov ax, 0F7h
        push ax
        call far ptr helper1
        add sp, 2
        call far ptr helper2
        _emit 0x5F
        _emit 0x5E
    }
}
