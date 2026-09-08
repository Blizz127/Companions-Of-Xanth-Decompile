int far in_port(unsigned port)
{
    _asm {
        mov dx, word ptr port
        in al, dx
        xor ah, ah
    }
}
