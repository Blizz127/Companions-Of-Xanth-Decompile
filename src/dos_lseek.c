int far dos_lseek(int fd, unsigned origin, unsigned long pos)
{
    _asm {
        mov ah, 42h
        mov al, byte ptr origin
        mov bx, word ptr fd
        mov cx, word ptr pos+2
        mov dx, word ptr pos
        int 21h
        jc err
        sub ax, ax
        jmp short done
        err:
        mov ax, 0ffffh
        done:
    }
}
