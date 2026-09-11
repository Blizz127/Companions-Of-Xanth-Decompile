extern int __near mn30CB;

int far ovl_14272(void)
{
    _asm {
        les ax, mn30CB
        cmp al,0x0
        retf
    }
}
