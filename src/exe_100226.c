char tbl[1];
unsigned long g;
void far helper(void);
void far exe_100226(int a)
{
    _asm {
        mov bl, byte ptr a
        and bx, 7
        mov al, byte ptr tbl[bx]
        cbw
        mov word ptr a, ax
        mov ax, 5
        mov bx, word ptr a
        int 33h
        call far ptr helper
        add ax, 12Ch
        adc dx, 0
        mov word ptr g, ax
        mov word ptr g+2, dx
    }
}
