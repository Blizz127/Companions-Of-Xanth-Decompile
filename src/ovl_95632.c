extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn0290;
extern int __near mn02A8;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_95632(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L14B
L0E:
        mov ax,mn6A06
        cmp ax,0x13
        jnz short $+5
        jmp LFD
L19:
        ja short $+10
        sub ax,0x12
        jz short $+33
        jmp L14B
L23:
        sub ax,0x2c
        jnz short $+5
        jmp L139
L2B:
        sub ax,0xa
        jnc short $+5
        jmp L14B
L33:
        sub ax,0x1
        ja short $+5
        jmp L139
L3B:
        jmp L14B
        nop
L3F:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+62
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x238f
        push ds
        push ax
        push word ptr mn0290
        mov ax,0x51
        push ax
        call far ptr helper_1
        add sp,0x8
        push dx
        push ax
        mov ax,0x10
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        jmp short $+108
        nop
L8F:
        push word ptr mn0290
        mov ax,0x11
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        call far ptr helper_3
        mov ax,0x2396
        push ds
        push ax
        call far ptr helper_4
        mov ax,0x4
        add sp,ax
        push ax
        call far ptr helper_5
        add sp,0x2
        mov ax,0x5
        push ax
        call far ptr helper_5
        add sp,0x2
        mov ax,0x2710
        push ax
        call far ptr helper_6
        add sp,0x2
        mov word ptr mn02A8,0x1
        mov ax,0x5a
        push ax
        call far ptr helper_7
        add sp,0x2
LF8:
        mov ax,0x1
        jmp short $+82
LFD:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x2381
        mov dx,ds
        jmp short $+9
        nop
L119:
        mov ax,0xe
        mov dx,0xf016
L11F:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0xd
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $-63
L139:
        mov ax,0xf
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $-81
L14B:
        xor ax,ax
L14D:
    }
}
