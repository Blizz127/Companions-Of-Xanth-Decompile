void far helper_0(void);
void far helper_1(void);
int far ovl_170343(int a)
{
    _asm {
        xor ax,ax
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+43
        mov ax,0xa
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+25
        mov ax,0x12
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L37:
        xor ax,ax
L39:
    }
}
