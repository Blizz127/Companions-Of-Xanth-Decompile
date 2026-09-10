void far helper2(void);
void far helper1(void);
void far exe_81139(int a, int b)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        push word ptr b
        push word ptr a
        call far ptr helper2
        add sp, 4
        mov ax, 0
        push ax
        call far ptr helper1
        add sp, 2
        _emit 0x5F
        _emit 0x5E
    }
}
