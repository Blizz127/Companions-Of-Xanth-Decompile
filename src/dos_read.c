int far dos_read(int fd, char far *buf, unsigned n)
{
    _asm {
        push ds
        mov ah, 3fh
        mov bx, word ptr fd
        mov cx, word ptr n
        mov dx, word ptr buf+2
        mov ds, dx
        mov dx, word ptr buf
        int 21h
        jnc ok
        sub ax, ax
        ok:
        pop ds
    }
}
