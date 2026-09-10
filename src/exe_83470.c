void far helper2(void);
void far helper1(void);
void far exe_83470(int a, int b)
{
    _asm {
        sub sp, 6
        cmp word ptr a, 5
        _emit 0x75
        _emit 0x06
        mov ax, 80h
        _emit 0xEB
        _emit 0x03
        _emit 0x90
        xor ax, ax
        push ax
        push word ptr b
        push word ptr a
        call far ptr helper2
        add sp, 4
        push dx
        push ax
        call far ptr helper1
    }
}
