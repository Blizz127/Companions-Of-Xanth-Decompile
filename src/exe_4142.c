extern int __near mn422C;
extern char __near mb4222;
extern char __near mb4227;
extern char __near mb41F4;
extern void __near nc00BF(void);

int near exe_4142(void)
{
    _asm {
        adc dl,0x0
        sub ax,0x1
        sbb dl,0x0
        mov mn422C,ax
        sub dl,mb4222
        mov mb4227,dl
        call nc00BF
        mov byte ptr mb41F4,0x1
        ret
    }
}
