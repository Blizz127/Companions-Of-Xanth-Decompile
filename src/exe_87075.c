int g;
void far helper(void);
void far exe_87075(char far *p)
{
    _asm {
        call far ptr helper
        xor ax, ax
        mov dx, 03C8h
        out dx, al
        push si
        push ds
        mov si, word ptr p
        mov ds, word ptr p+2
        mov cx, 100h
        inc dx
        mov al, byte ptr [si]
        inc si
        out dx, al
        mov al, byte ptr [si]
        inc si
        out dx, al
        mov al, byte ptr [si]
        inc si
        out dx, al
        _emit 0xE2
        _emit 0xF2
        pop ds
        pop si
        mov word ptr g, 0
    }
}
