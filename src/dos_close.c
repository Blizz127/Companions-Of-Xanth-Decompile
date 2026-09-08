int far dos_close(int fd)
{
    _asm {
        mov ah, 3eh
        mov bx, word ptr fd
        int 21h
    }
}
