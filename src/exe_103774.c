int g0;
int g1;
void far helper(void);
void far exe_103774(int a)
{
    _asm {
        sub sp, 4
        cmp word ptr a, 0
        _emit 0x7D
        _emit 0x08
        xor ax, ax
        mov word ptr g0, ax
        _emit 0xEB
        _emit 0x1C
        _emit 0x90
        lea ax, word ptr [bp-4]
        push ss
        push ax
        lea cx, word ptr [bp-2]
        push ss
        push cx
        push word ptr a
        call far ptr helper
        mov ax, word ptr [bp-2]
        mov word ptr g0, ax
        mov ax, word ptr [bp-4]
        mov word ptr g1, ax
    }
}
