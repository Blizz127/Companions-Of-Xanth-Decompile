extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far ovl_141337(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp LE5
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LDD
L16:
        jna short $+5
        jmp LE5
L1B:
        cmp al,0x2c
        jz short $+28
        ja short $+14
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+74
        jmp LE5
        nop
L2D:
        sub al,0x3a
        jz short $+66
        sub al,0xa
        jz short $+96
        jmp LE5
        nop
L39:
        cmp word ptr mn6A06,0x2c
        jnz short $+7
        mov ax,0x297e
        jmp short $+5
L45:
        mov ax,0x2983
L48:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3a
L5F:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
L69:
        mov sp,bp
L6B:
        mov ax,0x1
        jmp short $+121
        nop
L71:
        mov ax,0x60e
        push ax
        call far ptr helper_2
        mov sp,bp
        call far ptr helper_3
        xor ax,ax
        push ax
        call far ptr helper_4
        mov sp,bp
        call far ptr helper_5
        jmp short $-37
        nop
L93:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x38
        jmp short $-74
LAB:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x39
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        jmp short $-114
LDD:
        call far ptr helper_8
        jmp short $-119
        nop
LE5:
        xor ax,ax
LE7:
    }
}
