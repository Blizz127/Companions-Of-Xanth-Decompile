extern char __near mb6E09;
void far helper_0(void);
int far exe_103886(int a)
{
    _asm {
        xor ax,ax
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+18
        mov al,mb6E09
        and al,0x40
        cmp al,0x1
        cmc
        sbb ax,ax
        and ax,0x3
        jmp short $+5
        nop
L21:
        xor ax,ax
L23:
    }
}
