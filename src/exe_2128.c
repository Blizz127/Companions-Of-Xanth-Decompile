extern char __near mb41F4;
extern char __near mb0451;
extern char __near mb41FF;
extern char __near mb41FE;

int near exe_2128(void)
{
    _asm {
        mov byte ptr mb41F4,0x0
        mov byte ptr cs:mb0451,0x0
        mov byte ptr mb41FF,0x7
        mov byte ptr mb41FE,0x1
        ret
    }
}
