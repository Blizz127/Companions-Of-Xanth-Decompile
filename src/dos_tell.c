long far dos_tell(int fd)
{
    _asm {
        mov ah, 42h
        mov al, 1
        mov bx, word ptr fd
        sub cx, cx
        sub dx, dx
        int 21h
        jnc ok
        mov ax, 0ffffh
        cwd
        ok:
    }
}
