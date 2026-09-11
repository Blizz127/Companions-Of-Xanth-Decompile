extern int __near mn02A6;
int g;
void far helper_mkfp(void);
int far if15_127366(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+42
        cmp word ptr mn02A6,0x0
        jnz short $+22
        mov ax,0x23
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
        xor ax,ax
        jmp short $+19
        nop
L21:
        mov ax,0x24
        mov dx,0xf00e
        push dx
        push ax
        call far ptr helper_mkfp
L2E:
        mov ax,0x97
L31:
    }
}
