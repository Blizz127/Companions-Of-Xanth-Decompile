extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_83117(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L11D
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L117
L16:
        jna short $+5
        jmp L11D
L1B:
        sub al,0x13
        jz short $+16
        sub al,0x24
        jz short $+34
        sub al,0xd
        jnz short $+5
        jmp LF1
L2A:
        jmp L11D
L2D:
        mov ax,0x3e
L30:
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_0
L3A:
        mov sp,bp
L3C:
        mov ax,0x1
        jmp L11F
        nop
L43:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+27
        mov ax,0xe
        push ax
        mov ax,0x34
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+8
        mov ax,0x3f
        jmp short $-60
        nop
L6F:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x221b
        jmp short $+5
L87:
        mov ax,0x2220
L8A:
        push ds
        push ax
        mov ax,0x40
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+33
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        mov ax,0x4c
        push ax
        mov ax,0x3c
        push ax
        call far ptr helper_3
        jmp L3A
LCD:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        mov ax,0x4b
        push ax
        mov ax,0x3c
        push ax
        call far ptr helper_3
        add sp,0x4
        jmp L3C
        nop
LF1:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        mov ax,0x41
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp L3C
        nop
L117:
        mov ax,0x42
        jmp L30
L11D:
        xor ax,ax
L11F:
    }
}
