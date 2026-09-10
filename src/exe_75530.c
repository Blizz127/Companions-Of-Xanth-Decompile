int g0;
int g1;
void far helper2(void);
void far helper1(void);
int far exe_75530(void)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x04
        _emit 0x00
        _emit 0x56
        _emit 0x57
        mov ax, word ptr g0
        push ax
        mov ax, word ptr g1
        push ax
        call far ptr helper2
        add sp, 4
        mov word ptr [bp-4], ax
        call far ptr helper1
        mov ax, word ptr [bp-4]
        _emit 0xE9
        _emit 0x00
        _emit 0x00
        _emit 0x5F
        _emit 0x5E
    }
}
