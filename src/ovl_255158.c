extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_255158(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+97
        jmp LB9
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LB9
L1A:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+24
        push word ptr mn6A04
        mov ax,0x26
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x2f
        jmp short $+23
L43:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x30
L58:
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
L65:
        mov ax,0x1
        jmp short $+83
        nop
L6B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+66
        ja short $+70
        cmp al,0x38
        jz short $+48
        ja short $+12
        sub al,0xe
        jz short $+18
        sub al,0x5
        jz short $+32
        jmp short $+54
L85:
        sub al,0x42
        jz short $+38
        sub al,0x2
        jz short $+28
        jmp short $+44
L8F:
        mov ax,0x2d
L92:
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $-58
LA1:
        mov ax,0x2a
        jmp short $-18
        nop
LA7:
        mov ax,0x2b
        jmp short $-24
        nop
LAD:
        mov ax,0x2e
        jmp short $-30
        nop
LB3:
        mov ax,0x2c
        jmp short $-36
        nop
LB9:
        xor ax,ax
LBB:
    }
}
