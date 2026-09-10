void far helper(void);
int far if15_95972(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x1B
        mov ax, 0Eh
        push ax
        mov ax, 5Dh
        push ax
        call far ptr helper
        mov sp, bp
        cmp ax, 1
        cmc
        sbb ax, ax
        and ax, 63h
        _emit 0xEB
        _emit 0x18
        _emit 0x90
        mov ax, 0Eh
        push ax
        mov ax, 5Dh
        push ax
        call far ptr helper
        cmp ax, 1
        sbb ax, ax
        and al, 9Ch
        add ax, 63h
    }
}
