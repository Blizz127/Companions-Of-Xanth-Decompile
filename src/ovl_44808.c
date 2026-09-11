
int far ovl_44808(void)
{
    _asm {
        push dx
        add cx,bx
        xor [bx],bh
        add cx,bx
    }
}
