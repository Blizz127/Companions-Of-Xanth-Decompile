void far helper0(void);
void far helper6(void);
unsigned long far exe_6524(int a, int b, int c, int d, int e)
{
    _asm {
        sub sp, 8
        call far ptr helper0
        mov word ptr [bp-2], dx
        or dx, ax
        _emit 0x75
        _emit 0x06
        xor ax, ax
        cwd
        _emit 0xEB
        _emit 0x19
        _emit 0x90
        push word ptr [bp-2]
        push ax
        push word ptr e
        push word ptr d
        push word ptr c
        push word ptr b
        push word ptr a
        call far ptr helper6
    }
}
