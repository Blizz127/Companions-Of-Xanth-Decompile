void far helper(void);
int far if15_274104(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x74
        _emit 0x1B
        mov ax, 8
        push ax
        mov ax, 15Fh
        push ax
        call far ptr helper
        mov sp, bp
        cmp ax, 1
        cmc
        sbb ax, ax
        and ax, 178h
        _emit 0xEB
        _emit 0x19
        _emit 0x90
        mov ax, 8
        push ax
        mov ax, 15Fh
        push ax
        call far ptr helper
        cmp ax, 1
        sbb ax, ax
        and ax, 0FE87h
        add ax, 178h
    }
}
