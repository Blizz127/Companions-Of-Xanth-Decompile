int arr[1];
void far helper(void);
int far exe_91727(int a)
{
    _asm {
        sub sp, 2
        push word ptr a
        call far ptr helper
        add sp, 2
        or ax, ax
        _emit 0x7D
        _emit 0x05
        mov ax, 0FFFFh
        _emit 0xEB
        _emit 0x08
        mov bx, ax
        add bx, ax
        mov ax, word ptr arr[bx]
    }
}
