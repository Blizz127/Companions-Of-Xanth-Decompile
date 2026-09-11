extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_198308(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp LBD
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LBD
L1A:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x13
L40:
        mov dx,0xf022
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+112
        nop
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+76
        ja short $+98
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+28
        sub al,0x19
        jnz short $+86
L69:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x11
        jmp short $-61
L7F:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0xf
        jmp short $+5
L97:
        mov ax,0x10
L9A:
        mov dx,0xf022
        push dx
        push ax
        mov ax,0xe
        jmp short $-98
        nop
LA5:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x12
        jmp short $-122
        nop
LBD:
        xor ax,ax
LBF:
    }
}
