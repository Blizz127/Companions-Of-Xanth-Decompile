void far helper(void);
int far exe_83669(int a, char far *p, int n)
{
    _asm {
        sub sp, 6
        dec word ptr n
        _emit 0x78
        _emit 0x27
        push word ptr a
        call far ptr helper
        add sp, 2
        mov word ptr [bp-2], ax
        inc ax
        _emit 0x74
        _emit 0x12
        mov al, byte ptr [bp-2]
        les bx, dword ptr p
        inc word ptr p
        mov byte ptr es:[bx], al
        cmp al, 0Ah
        _emit 0x75
        _emit 0xDA
        _emit 0xEB
        _emit 0x04
        xor ax, ax
        _emit 0xEB
        _emit 0x03
        mov ax, 1
    }
}
