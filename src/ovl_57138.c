extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_57138(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr mn6A04,0x1
        jnz short $+5
        jmp LD7
L0D:
        mov ax,0x17
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp LD7
L24:
        mov ax,0xf
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp LBF
L3B:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+32
        mov ax,0x1d1f
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_1
        add sp,0x8
        push dx
        push ax
        mov ax,0x1d23
        push ds
        jmp L104
L6D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d2f
        push ds
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x2
        cmp ax,0x8
        jnz short $+95
        mov ax,0x2c
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        jmp short $+77
LBF:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2
        jmp short $+44
        nop
LD7:
        cmp word ptr mn6A04,0x1
        jnz short $+9
        mov ax,0x1d16
        mov dx,ds
        jmp short $+18
LE5:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
LF5:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x1
L100:
        mov dx,0xf029
        push dx
L104:
        push ax
        call far ptr helper_2
L10A:
        mov ax,0x1
    }
}
