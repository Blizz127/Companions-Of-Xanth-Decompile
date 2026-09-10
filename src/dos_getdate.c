int far dos_getdate(char far *p)
{
    _asm {
        mov ah, 2ah
        int 21h
        push ds
        lds bx, dword ptr p
        mov word ptr [bx+2], cx
        mov byte ptr [bx+1], dh
        mov byte ptr [bx], dl
        mov byte ptr [bx+4], al
        pop ds
        xor ax, ax
    }
}
