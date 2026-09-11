
int far exe_4744(void)
{
    _asm {
        mov ah,0x30
        int 0x21
        cmp al,0x2
        jnc short $+7
        xor ax,ax
        push es
        push ax
        retf
L0D:
    }
}
