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
int far ovl_67056(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L19D
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L185
L16:
        jna short $+5
        jmp L19D
L1B:
        sub al,0x8
        jz short $+20
        sub al,0xb
        jz short $+98
        sub al,0x19
        jnz short $+5
        jmp LAD
L2A:
        sub al,0xe
        jz short $+87
        jmp L19D
L31:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x5
        jmp short $+24
        nop
L5B:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x6
L70:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
L7D:
        mov ax,0x1
        jmp L19F
L83:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+18
L97:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
LA1:
        add sp,0x4
        jmp short $-39
        nop
LA7:
        mov ax,0x1
        jmp short $-19
        nop
LAD:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2
        jmp short $-102
        nop
LD9:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+32
        mov ax,0x1e42
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_1
        add sp,0x8
        push dx
        push ax
        mov ax,0x3
        jmp L70
        nop
L10B:
        mov ax,0x58
        push ax
        call far ptr helper_4
        add sp,0x2
        or ax,ax
        jnz short $+60
        mov ax,0x4
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x58
        push ax
        call far ptr helper_5
        add sp,0x2
        mov ax,0x51
        push ax
        call far ptr helper_5
        add sp,0x2
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x6
        jmp short $+33
L155:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e46
        push ds
        push ax
        call far ptr helper_2
        add sp,0x8
L174:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        jmp LA1
        nop
L185:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x7
        jmp L70
L19D:
        xor ax,ax
L19F:
    }
}
