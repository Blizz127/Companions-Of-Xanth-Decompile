extern int __near mn6A06;
void far helper_0(void);
int far ovl_96822(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+41
        mov ax,mn6A06
        sub ax,0x12
        jz short $+7
        dec ax
        jz short $+24
        jmp short $+28
L15:
        mov ax,0x23
L18:
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+10
L29:
        mov ax,0x22
        jmp short $-20
        nop
L2F:
        xor ax,ax
L31:
    }
}
