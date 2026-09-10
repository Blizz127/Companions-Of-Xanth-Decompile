int g;
void far helper(void);
void far exe_87203(void)
{
    _asm {
        sub sp, 0Eh
        mov byte ptr [bp-0Dh], 9
        mov byte ptr [bp-0Eh], 0DBh
        mov byte ptr [bp-0Bh], 0
        cmp word ptr g, 1
        cmc
        sbb al, al
        and al, 0Dh
        mov byte ptr [bp-0Ch], al
        mov word ptr [bp-0Ah], 1
        lea ax, word ptr [bp-0Eh]
        push ss
        push ax
        push ss
        push ax
        mov ax, 10h
        push ax
        call far ptr helper
    }
}
