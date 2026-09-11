extern int __near mn02BA;
int g;
void far helper1(void);
void far helper2(void);
int far if15_167004(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+87
        mov ax,0x13
        push ax
        call far ptr helper1
        mov sp,bp
        or ax,ax
        jz short $+22
        mov ax,0x5a04
        push ax
        mov ax,0x2fd
L1C:
        push ax
        call far ptr helper2
        mov sp,bp
L24:
        xor ax,ax
        jmp short $+56
        nop
L29:
        mov ax,0x14
        push ax
        call far ptr helper1
        mov sp,bp
        or ax,ax
        jz short $+37
        cmp word ptr mn02BA,0x8
        jnl short $+12
        mov ax,0x5a03
        push ax
        mov ax,0x145
        jmp short $+-42
        nop
L49:
        mov ax,0x5a04
        push ax
        mov ax,0x2fd
        push ax
        call far ptr helper2
        add sp,0x4
        jmp short $+-53
L5B:
        mov ax,0xc5
L5E:
    }
}
