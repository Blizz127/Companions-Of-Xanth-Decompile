char g;
void far helper(void);
void far helper_mkfp(void);
void far helper2(void);
void far helper3(void);
void far helper4(void);
int far if15_320227(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x74
        _emit 0x05
        mov ax, 1D5h
        _emit 0xEB
        _emit 0x56
        mov ax, 1CEh
        push ax
        mov ax, 1C3h
        push ax
        call far ptr helper
        mov sp, bp
        or ax, ax
        _emit 0x74
        _emit 0x1D
        mov ax, 22h
        mov dx, 0F04Ah
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp, bp
        mov ax, 3AA5h
        push ds
        push ax
        call far ptr helper2
        mov sp, bp
        _emit 0xEB
        _emit 0xCB
        mov ax, 23h
        mov dx, 0F04Ah
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp, bp
        mov ax, 1388h
        push ax
        call far ptr helper3
        mov sp, bp
        mov byte ptr g, 1
        call far ptr helper4
        xor ax, ax
    }
}
