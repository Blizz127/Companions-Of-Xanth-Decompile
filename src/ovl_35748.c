
int far ovl_35748(void)
{
    _asm {
        mov word ptr [bx],0x30cb
        std
        pop es
        retf
    }
}
