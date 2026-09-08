void far * far get_vect(int v)
{
    _asm {
        mov ax, word ptr v
        mov ah, 35h
        int 21h
        mov dx, es
        mov ax, bx
    }
}
