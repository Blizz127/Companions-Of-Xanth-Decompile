void far * far dos_alloc(unsigned nbytes)
{
    _asm {
        mov ax, word ptr nbytes
        mov bx, 10h
        div bx
        or dx, dx
        jz skip
        inc ax
        skip:
        mov bx, ax
        mov ah, 48h
        int 21h
        mov dx, ax
        xor ax, ax
        jnc ok
        xor dx, dx
        ok:
    }
}
