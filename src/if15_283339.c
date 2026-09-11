extern int __near mn02D8;
int g;
void far helper_mkfp(void);
void far helper2(void);
void far helper3(void);
int far if15_283339(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+55
        cmp word ptr mn02D8,0xa
        jnl short $+48
        mov ax,0x13
        mov dx,0xf03f
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
        mov ax,0x1388
        push ax
        call far ptr helper2
        mov sp,bp
        mov ax,0x5a18
        push ax
        mov ax,0x3e9
        push ax
        call far ptr helper3
        mov sp,bp
        xor ax,ax
        jmp short $+6
        nop
L3B:
        mov ax,0x174
L3E:
    }
}
