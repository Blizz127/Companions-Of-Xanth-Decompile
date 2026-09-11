extern char __near mb0338;
void far helper_0(void);
void far helper_1(void);
int far ovl_159472(void)
{
    _asm {
        mov ax,0x1
        push ax
        mov ax,0x93
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+30
        cmp byte ptr mb0338,0x0
        jnz short $+23
        mov byte ptr mb0338,0x1
        xor ax,ax
        push ax
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_1
        add sp,0x6
L30:
        retf
    }
}
