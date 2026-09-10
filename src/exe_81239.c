void far helper(void);
void far exe_81239(int a, int b)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        mov ax, 20h
        push ax
        mov ax, 0
        mov dx, 2EC2h
        push dx
        push ax
        push word ptr b
        push word ptr a
        call far ptr helper
        add sp, 0Ah
        _emit 0x5F
        _emit 0x5E
    }
}
