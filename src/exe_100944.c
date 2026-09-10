int g0;
int g1;
void far helper(void);
void far exe_100944(int a, int b)
{
    _asm {
        sub sp, 2
        mov ax, word ptr a
        mov dx, word ptr b
        mov word ptr g0, ax
        mov word ptr g1, dx
        mov ax, 0FD85h
        mov dx, 08A7h
        push dx
        push ax
        mov ax, 0FDF0h
        mov dx, 08A7h
        push dx
        push ax
        mov ax, 1596h
        mov cx, 3420h
        push cx
        push ax
        call far ptr helper
    }
}
