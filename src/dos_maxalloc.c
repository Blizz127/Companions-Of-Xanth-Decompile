unsigned far dos_maxalloc(void)
{
    _asm {
        mov ah, 48h
        mov bx, 0ffffh
        int 21h
        mov ax, 10h
        mul bx
    }
}
