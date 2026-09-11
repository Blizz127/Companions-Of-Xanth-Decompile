extern int __near mn421F;

int near exe_3822(void)
{
    _asm {
        push cx
        mov dx,mn421F
        add dl,0xe
        mov cx,0x200
L0B:
        in al,dx
        or al,al
        js short $+7
        loop L0B
        pop cx
        stc
        ret
L15:
    }
}
