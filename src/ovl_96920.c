extern int __near mn6A06;
void far helper_0(void);
int far ovl_96920(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+31
        mov ax,mn6A06
        sub ax,0x13
        jnz short $+23
        mov ax,0x25
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+5
        nop
L25:
        xor ax,ax
L27:
    }
}
