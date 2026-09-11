
int near exe_123531(void)
{
    _asm {
        push ax
        push dx
        mov bx,0x12
        mul bx
        mov bx,ax
        add bx,0xd39
        pop dx
        pop ax
        ret
    }
}
