void far helper3(void);
void far helper(void);
void far helper_mkfp(void);
int far if15_208725(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x3D
        xor ax, ax
        push ax
        mov cx, 11h
        push cx
        mov cx, 127h
        push cx
        call far ptr helper3
        mov sp, bp
        or ax, ax
        _emit 0x74
        _emit 0x27
        mov ax, 1
        push ax
        mov ax, 124h
        push ax
        call far ptr helper
        mov sp, bp
        or ax, ax
        _emit 0x75
        _emit 0x14
        mov ax, 5Ah
        mov dx, 0F025h
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp, bp
        xor ax, ax
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        mov ax, 10Ch
    }
}
