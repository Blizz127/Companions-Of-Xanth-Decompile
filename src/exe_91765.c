int arr[1];
void far helper(void);
int far exe_91765(int a)
{
    _asm {
        sub sp, 2
        push word ptr a
        call far ptr helper
        add sp, 2
        or ax, ax
        _emit 0x7D
        _emit 0x05
        xor ax, ax
        _emit 0xEB
        _emit 0x09
        _emit 0x90
        mov bx, ax
        add bx, ax
        mov ax, word ptr arr[bx]
    }
}
