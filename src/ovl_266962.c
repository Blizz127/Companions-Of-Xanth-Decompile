extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_266962(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+115
        jmp L13F
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L13F
L1A:
        mov ax,0x5
        push ax
        mov ax,0x158
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+8
        mov ax,0x3569
        jmp short $+6
        nop
L33:
        mov ax,0x356d
L36:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x5
        push ax
        mov ax,0x158
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x3573
        jmp short $+5
L63:
        mov ax,0x3576
L66:
        push ds
        push ax
        mov ax,0x10
L6B:
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
L77:
        mov ax,0x1
        jmp L141
L7D:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L139
L88:
        jna short $+5
        jmp L13F
L8D:
        sub al,0x8
        jz short $+20
        sub al,0xa
        jz short $+38
        dec al
        jz short $+54
        sub al,0x19
        jnz short $+5
        jmp L121
LA0:
        jmp L13F
LA3:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0xe
        jmp short $-76
LB9:
        xor ax,ax
        push ax
        mov ax,0x152
        push ax
        push word ptr mn6A06
        call far ptr helper_3
        mov sp,bp
        jmp short $+118
LCD:
        mov ax,0x9
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0xa
        push ax
        mov ax,0x155
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+46
        mov ax,0xa
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        push word ptr mn0256
        mov ax,0x157
        push ax
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jnz short $+5
        jmp L77
L114:
        mov ax,0xb
        jmp L6B
        nop
L11B:
        mov ax,0xc
        jmp L6B
L121:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0xd
        jmp L6B
        nop
L139:
        mov ax,0xf
        jmp L6B
L13F:
        xor ax,ax
L141:
    }
}
