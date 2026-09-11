extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_293905(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L91
L0F:
        jmp L15F
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L15F
L1E:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+24
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0xb
        jmp short $+58
L47:
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xc
L7F:
        mov dx,0xf01e
L82:
        push dx
        push ax
        call far ptr helper_2
L89:
        mov sp,bp
        mov ax,0x1
        jmp L161
L91:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L159
L9C:
        jna short $+5
        jmp L15F
LA1:
        cmp al,0x13
        jz short $+92
        ja short $+14
        sub al,0x8
        jz short $+18
        sub al,0x6
LAD:
        jz short $+26
        jmp L15F
        nop
LB3:
        sub al,0x2c
        jz short $+6
        sub al,0x16
        jmp short $-12
LBB:
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $-59
        nop
LC7:
        cmp word ptr mn0256,0x18a
        jz short $+8
        mov ax,0x7
        jmp short $-83
        nop
LD5:
        cmp word ptr mn6A06,0xe
        jnz short $+7
        mov ax,0x9
        jmp short $+5
LE1:
        mov ax,0xa
LE4:
        mov dx,0xf01e
        push dx
        push ax
        cmp word ptr mn6A06,0xe
        jnz short $+7
        mov ax,0x3899
        jmp short $+5
LF5:
        mov ax,0x389e
LF8:
        push ds
        push ax
        mov ax,0x8
        jmp short $-123
LFF:
        mov ax,0x185
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x3
        mov dx,0xf01e
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        cmp word ptr mn0256,0x18a
        jz short $+16
        cmp word ptr mn0256,0x184
        jz short $+8
        mov ax,0x5
        jmp L7F
L135:
        mov ax,0xe
        push ax
        mov ax,0x18c
        push ax
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x388a
        jmp short $+5
L14D:
        mov ax,0x3892
L150:
        push ds
        push ax
        mov ax,0x4
        jmp L7F
        nop
L159:
        mov ax,0x6
        jmp L7F
L15F:
        xor ax,ax
L161:
    }
}
