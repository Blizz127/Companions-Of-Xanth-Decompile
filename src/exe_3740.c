extern int __near mn421F;
extern void __near nc0030(void);
extern void __near nc006E(void);
extern void __near nc0052(void);
extern void __near nc0382(void);

int near exe_3740(void)
{
    _asm {
        mov dx,mn421F
        call nc0030
        jc short $+39
        mov dx,mn421F
        add dl,0xc
        mov al,0xe0
        call nc006E
        jc short $+25
        mov al,0xc6
        call nc006E
        jc short $+18
        call nc0052
        jc short $+13
        cmp al,0x39
        jnz short $+9
        mov al,0x1
        call nc0382
        clc
        ret
L2E:
    }
}
