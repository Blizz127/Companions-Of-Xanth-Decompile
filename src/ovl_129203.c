extern int __near mn6232;
extern char __near mbCB32;

int far ovl_129203(void)
{
    _asm {
        xor bh,[bp+si]
        or bx,mn6232
        or bl,mbCB32
    }
}
