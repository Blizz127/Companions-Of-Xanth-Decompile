extern int __near mn421F;
extern void __near nc0022(void);

int near exe_3788(void)
{
    _asm {
        mov dx,mn421F
        add dl,0x6
        mov al,0x1
        out dx,al
        sub al,al
L0C:
        inc al
        jnz short $-2
        out dx,al
        mov cl,0x20
L13:
        call nc0022
        cmp al,0xaa
        jz short $+8
        dec cl
        jnz short $-9
        stc
        ret
L20:
    }
}
