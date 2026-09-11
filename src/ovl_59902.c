extern int __near mn69FE;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_59902(void)
{
    _asm {
        cmp word ptr mn69FE,0x5
        jnz short $+31
        mov ax,0x1dd9
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_0
        add sp,0x8
        push dx
        push ax
        mov ax,0x1de0
        push ds
        jmp short $+32
L24:
        mov ax,0x1de8
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_0
        add sp,0x8
        push dx
        push ax
        mov ax,0x1f
        mov dx,0xf029
        push dx
L42:
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x1
        retf
    }
}
