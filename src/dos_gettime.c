int far dos_gettime(char far *p)
{
    _asm {
        mov ah, 2ch
        int 21h
        push ds
        lds bx, dword ptr p
        mov byte ptr [bx], ch
        mov byte ptr [bx+1], cl
        mov byte ptr [bx+2], dh
        mov byte ptr [bx+3], dl
        pop ds
        xor ax, ax
    }
}
