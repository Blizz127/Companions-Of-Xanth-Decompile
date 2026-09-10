void far helper(void);
void far helper_mkfp(void);
int far if15_299476(int a)
{
    _asm {
        mov ax, 0Ah
        push ax
        mov ax, 195h
        push ax
        call far ptr helper
        mov sp, bp
        or ax, ax
        _emit 0x74
        _emit 0x1A
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x0F
        mov ax, 20h
        mov dx, 0F046h
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp, bp
        mov ax, 19Ah
        _emit 0xEB
        _emit 0x0D
        cmp word ptr a, 15
        _emit 0x74
        _emit 0x04
        xor ax, ax
        _emit 0xEB
        _emit 0x03
        mov ax, 0FFFFh
    }
}
