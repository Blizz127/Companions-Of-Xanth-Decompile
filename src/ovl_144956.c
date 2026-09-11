extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn0256;
extern char __near mb0783;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_144956(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L185
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L17F
L16:
        jna short $+5
        jmp L185
L1B:
        sub al,0x8
        jz short $+26
        sub al,0xb
        jnz short $+5
        jmp LE3
L26:
        sub al,0xe
        jnz short $+5
        jmp L105
L2D:
        sub al,0xb
        jnz short $+5
        jmp L117
L34:
        jmp L185
L37:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+35
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x20
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_2
        jmp short $+114
        nop
L6B:
        cmp word ptr mn0256,0x9d
        jz short $+34
        mov byte ptr mb0783,0x1
        mov ax,0x9d
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x21
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_2
        jmp short $+12
        nop
L93:
        mov ax,0x59
        push ax
        call far ptr helper_4
L9C:
        mov sp,bp
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x22
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        mov sp,bp
        mov ax,0x2c
        push ax
        push word ptr mn6A04
        call far ptr helper_6
LDA:
        mov sp,bp
LDC:
        mov ax,0x1
        jmp L187
        nop
LE3:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x29b4
        jmp short $+5
LFB:
        mov ax,0x29b9
LFE:
        push ds
        push ax
        mov ax,0x1d
        jmp short $+61
L105:
        mov ax,0x24
L108:
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_2
L112:
        add sp,0x4
        jmp short $-57
L117:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+38
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e
L140:
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $-113
L14F:
        mov ax,0x1f
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x4
        mov ax,0x8
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        jmp short $-106
        nop
L17F:
        mov ax,0x23
        jmp short $-122
        nop
L185:
        xor ax,ax
L187:
    }
}
