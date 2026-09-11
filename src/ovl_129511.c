extern int __near mn1432;
extern int __near mnCB32;

int far ovl_129511(void)
{
    _asm {
        xor ah,[bx]
        add mn1432,bx
        add mnCB32,bx
    }
}
