extern int __near mnE032;
extern int __near mnCB32;

int far ovl_239947(void)
{
    _asm {
        xor dh,ch
        add bx,mnE032
        add bx,mnCB32
    }
}
