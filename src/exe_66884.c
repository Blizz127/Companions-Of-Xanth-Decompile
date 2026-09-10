char g;
void far helper(void);
void far exe_66884(void)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        mov al, byte ptr g
        cbw
        cmp ax, 0
        _emit 0x75
        _emit 0x03
        _emit 0xE9
        _emit 0x06
        _emit 0x00
        mov ax, 40h
        _emit 0xE9
        _emit 0x03
        _emit 0x00
        mov ax, 0
        push ax
        mov ax, 8
        push ax
        call far ptr helper
        add sp, 4
        _emit 0x5F
        _emit 0x5E
    }
}
