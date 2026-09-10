void far helper(void);
void far helper_mkfp(void);
int far if15_292486(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x27
        mov ax, 0Eh
        push ax
        mov ax, 187h
        push ax
        call far ptr helper
        mov sp, bp
        or ax, ax
        _emit 0x75
        _emit 0x14
        mov ax, 25h
        mov dx, 0F045h
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp, bp
        xor ax, ax
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        mov ax, 18Ah
    }
}
