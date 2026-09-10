void far helper_c7(void);
void far ge_c7(int a)
{
    _asm {
        cmp word ptr a, 0C7h
        jl skip
        mov ax, 0C8h
        push ax
        mov ax, 0137h
        mov cx, 3181h
        push cx
        push ax
        call far ptr helper_c7
        skip:
    }
}
