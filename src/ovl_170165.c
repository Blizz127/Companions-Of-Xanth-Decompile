extern int __near mn02EA;
extern int __near mn02EC;

int far ovl_170165(void)
{
    _asm {
        cmp word ptr mn02EA,0x4
        jnz short $+15
        cmp word ptr mn02EC,0x1
        jnz short $+8
        mov ax,0x1
        jmp short $+5
        nop
L14:
        xor ax,ax
L16:
        retf
    }
}
