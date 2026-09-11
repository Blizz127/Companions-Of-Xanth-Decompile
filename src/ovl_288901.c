void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_288901(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+61
        mov ax,0xa
        push ax
        push word ptr [bp+0x8]
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+23
        mov ax,0x2
        push ax
        push word ptr [bp+0x8]
        call far ptr helper_1
        mov sp,bp
        mov ax,0x37d2
L29:
        mov dx,ds
        jmp short $+25
L2D:
        mov ax,0x2
        push ax
        push word ptr [bp+0x8]
        call far ptr helper_2
        mov sp,bp
        mov ax,0x37d9
        jmp short $-21
        nop
L41:
        xor ax,ax
        cwd
L44:
    }
}
