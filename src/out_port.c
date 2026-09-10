int far out_port(unsigned port, unsigned char val)
{
    _asm {
        mov dx, word ptr port
        mov al, byte ptr val
        out dx, al
        mov ah, 0
    }
}
