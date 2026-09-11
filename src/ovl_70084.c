extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_70084(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L1C3
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1AB
L16:
        jna short $+5
        jmp L1C3
L1B:
        sub al,0x8
        jz short $+20
        sub al,0xb
        jz short $+54
        sub al,0x19
        jz short $+12
        sub al,0xc
        jnz short $+5
        jmp LF1
L2E:
        jmp L1C3
L31:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x3e
L45:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_1
L4F:
        mov sp,bp
        mov ax,0x1
        jmp L1C5
L57:
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        cmp ax,0x110
        jnz short $+8
        mov ax,0x39
        jmp short $+6
        nop
L6D:
        mov ax,0x3a
L70:
        mov dx,0xf015
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x38
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x31
        push ax
        mov ax,0x56
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jnz short $+21
        mov ax,0x51
        push ax
        mov ax,0x56
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+42
LBC:
        push word ptr mn6A04
        call far ptr helper_4
        mov sp,bp
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x3b
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
LE4:
        mov ax,0x2e
        push ax
        call far ptr helper_5
        jmp L4F
        nop
LF1:
        cmp word ptr mn6A02,0x31
        jz short $+5
        jmp L1C3
LFB:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+43
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3c
        jmp L45
L137:
        mov ax,0xe
        push ax
        push word ptr mn6A02
        call far ptr helper_6
        mov sp,bp
        or ax,ax
        jz short $+123
        mov ax,0x31
        push ax
        mov cx,0x22
        push cx
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
        mov ax,0x56
        push ax
        call far ptr helper_2
        add sp,0x2
        cmp ax,0x110
        jnz short $+7
        mov ax,0x1e9d
        jmp short $+5
L183:
        mov ax,0x1ea3
L186:
        push ds
        push ax
        mov ax,0x3d
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        push ax
        mov ax,0x31
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        jmp L4F
L1AB:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x3f
        jmp L45
        nop
L1C3:
        xor ax,ax
L1C5:
    }
}
