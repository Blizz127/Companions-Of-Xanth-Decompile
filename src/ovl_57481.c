extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_57481(void)
{
    _asm {
        mov ax,0x17
        push ax
        push word ptr mn6A02
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+94
        mov ax,0x8
        push ax
        push word ptr mn6A02
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+74
        push word ptr mn6A02
        mov ax,0x4
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x4
        mov dx,0xf029
        push dx
        push ax
        call far ptr helper_2
        add sp,0x10
        jmp short $+59
L70:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d40
        push ds
        push ax
        push word ptr mn6A02
        mov ax,0x52
        push ax
        call far ptr helper_1
        add sp,0x8
        push dx
        push ax
        mov ax,0x5
        mov dx,0xf029
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
LA9:
        mov ax,0x1
        retf
    }
}
