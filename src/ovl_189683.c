extern char __near mbBA32;
extern int __near mnCB32;

int far ovl_189683(void)
{
    _asm {
        xor ch,dl
        adc mbBA32,bl
        adc mnCB32,bx
    }
}
