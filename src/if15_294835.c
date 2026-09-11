extern int __near mn02DC;
int g;
void far helper_mkfp(void);
int far if15_294835(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+29
        cmp word ptr mn02DC,0x3
        jnl short $+22
        mov ax,0x1e
        mov dx,0xf01e
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
        xor ax,ax
        jmp short $+6
        nop
L21:
        mov ax,0x18d
L24:
    }
}
