extern int __near mn4196;
extern char __near mb416E;
void far helper_0(void);
int far ovl_11884(void)
{
    _asm {
        cmp word ptr mn4196,0x0
        jz short $+27
        test byte ptr mb416E,0x8
        jnz short $+10
        or byte ptr mb416E,0x8
        jmp short $+13
        nop
L16:
        call far ptr helper_0
        and byte ptr mb416E,0xf7
L20:
        retf
    }
}
