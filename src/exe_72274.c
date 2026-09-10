int arr[1];
void far helper1(void);
void far helper2(void);
void far exe_72274(int a)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        mov bx, word ptr a
        shl bx, 1
        add word ptr arr[bx], 1
        push word ptr a
        call far ptr helper1
        add sp, 2
        mov bx, word ptr a
        shl bx, 1
        add word ptr arr[bx], ax
        mov ax, 0F8h
        push ax
        call far ptr helper2
        add sp, 2
        _emit 0x5F
        _emit 0x5E
    }
}
