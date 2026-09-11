extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_57414(void)
{
    _asm {
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+46
        mov ax,0x1d3c
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_1
        add sp,0x8
        push dx
        push ax
        mov ax,0x3
        mov dx,0xf029
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0x1
        jmp short $+4
L40:
        xor ax,ax
L42:
        retf
    }
}
