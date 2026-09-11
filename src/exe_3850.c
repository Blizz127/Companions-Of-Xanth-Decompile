
int near exe_3850(void)
{
    _asm {
        push cx
        mov ah,al
        mov cx,0x2000
L06:
        in al,dx
        or al,al
        jns short $+7
        loop L06
        pop cx
        stc
        ret
L10:
    }
}
