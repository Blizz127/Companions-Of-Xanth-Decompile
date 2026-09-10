int far dos_setvect(int v, void far *p)
{
    _asm {
        mov ax, word ptr v
        push ds
        lds dx, dword ptr p
        mov ah, 25h
        int 21h
        pop ds
        xor ax, ax
    }
}
