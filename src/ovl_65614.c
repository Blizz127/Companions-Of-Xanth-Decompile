extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_65614(void)
{
    _asm {
        mov ax,0x1
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x6
        or ax,ax
        jnz short $+85
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e34
        push ds
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0x1
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x6
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x2
        cmp ax,0x53
        jnz short $+54
        mov ax,0x3b
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        jmp short $+36
L68:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x55
        mov dx,0xf012
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
L8A:
        mov ax,0x1
        retf
    }
}
