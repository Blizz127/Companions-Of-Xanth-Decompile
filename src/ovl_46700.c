extern char __near mbCB0B;

int far ovl_46700(void)
{
    _asm {
        mov al,mbCB0B
        xor [bx],ch
        or cx,bx
    }
}
