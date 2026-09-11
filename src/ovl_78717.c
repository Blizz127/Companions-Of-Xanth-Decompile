extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_78717(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp LC5
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LC5
L1A:
        mov ax,0x31
        push ax
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x56
        push ax
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
L40:
        mov dx,0xf032
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+120
        nop
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x2c
        jz short $+14
        ja short $+106
        sub al,0x8
        jz short $+8
        sub al,0xb
        jz short $+26
        jmp short $+96
L67:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x13
        jmp short $-59
L7D:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x1ff3
        jmp short $+5
L95:
        mov ax,0x1ff8
L98:
        push ds
        push ax
        mov ax,0x27
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x12
        jmp L40
        nop
LC5:
        xor ax,ax
LC7:
    }
}
