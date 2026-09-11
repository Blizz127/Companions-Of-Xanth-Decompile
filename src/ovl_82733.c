extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_82733(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L177
L0E:
        mov ax,mn6A06
        cmp ax,0x4c
        jnz short $+5
        jmp LCD
L19:
        jna short $+5
        jmp L177
L1E:
        cmp al,0x44
        jz short $+119
        ja short $+15
        sub al,0x13
        jz short $+25
        sub al,0x19
        jz short $+85
        jmp L177
        nop
        nop
L31:
        sub al,0x45
        jz short $+118
        sub al,0x6
        jnz short $+5
        jmp LE7
L3C:
        jmp L177
L3F:
        mov ax,0xa
        push ax
        mov ax,0x3d
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x39
        mov dx,0xf004
        jmp short $+7
L5B:
        mov ax,0x21fc
        mov dx,ds
L60:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x38
L6B:
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
L78:
        mov ax,0x1
        jmp L179
        nop
L7F:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x3a
        jmp short $-41
        nop
L97:
        mov ax,0x3b
        mov dx,0xf004
        push dx
L9E:
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-47
LA9:
        mov ax,0xa
        push ax
        mov ax,0x3d
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x220e
        jmp short $+6
        nop
LC3:
        mov ax,0x2212
LC6:
        push ds
        push ax
        mov ax,0x3d
        jmp short $-96
LCD:
        mov ax,0xa
        push ax
        mov ax,0x3d
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+8
        mov ax,0x2200
        push ds
        jmp short $-71
LE7:
        cmp word ptr mn6A06,0x4c
        jnz short $+22
        mov ax,0xa
        push ax
        mov ax,0x3d
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+29
L102:
        cmp word ptr mn6A06,0x4b
        jnz short $+90
        mov ax,0xa
        push ax
        mov ax,0x3d
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+70
L11D:
        mov ax,0xa
        push ax
        mov ax,0x3d
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x2209
        jmp short $+6
        nop
L137:
        mov ax,0x220b
L13A:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x3c
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp L78
L161:
        xor ax,ax
        push ax
        mov ax,0x3d
        push ax
        mov ax,0x37
        push ax
        call far ptr helper_3
        add sp,0x6
        jmp short $+5
        nop
L177:
        xor ax,ax
L179:
    }
}
