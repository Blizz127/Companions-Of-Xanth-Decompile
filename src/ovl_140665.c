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
void far helper_8(void);
void far helper_9(void);
void far helper_10(void);
int far ovl_140665(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LA5
L0F:
        jmp L297
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L297
L1E:
        cmp word ptr mn6A04,0xa5
        jnz short $+73
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+54
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x36
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $+51
        nop
L6D:
        push word ptr mn6A04
        mov ax,0x2
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
        mov ax,0x37
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
L9D:
        mov sp,bp
L9F:
        mov ax,0x1
        jmp L299
LA5:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L28F
LB0:
        jna short $+5
        jmp L297
LB5:
        cmp al,0x2c
        jnz short $+5
        jmp L15F
LBC:
        ja short $+13
        sub al,0x8
        jz short $+27
        sub al,0xb
        jz short $+117
        jmp L297
LC9:
        sub al,0x3a
        jnz short $+5
        jmp L1ED
LD0:
        sub al,0xa
        jnz short $+5
        jmp L1FD
LD7:
        jmp L297
        nop
LDB:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_4
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
        mov ax,0x33
        jmp L226
L105:
        mov ax,0x34
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        mov ax,0x2c
L128:
        push ax
        push word ptr mn6A04
        call far ptr helper_6
L132:
        add sp,0x4
        jmp L9F
        nop
L139:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x2972
        jmp short $+6
        nop
L153:
        mov ax,0x2977
L156:
        push ds
        push ax
        mov ax,0x2d
        jmp L226
        nop
L15F:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x30
        jmp L226
L18B:
        mov ax,0x31
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        push ax
        mov ax,0xa5
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+30
        mov ax,0x32
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0xa5
        push ax
        call far ptr helper_7
        add sp,0x2
L1CB:
        mov ax,0x2e
        push ax
        call far ptr helper_8
        add sp,0x2
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x4
        mov ax,0x8
        jmp L128
L1ED:
        mov ax,0x35
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        jmp L132
L1FD:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+40
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2e
L226:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp L9F
        nop
L237:
        mov ax,0xa3
        push ax
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
        mov ax,0x2f
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x6
        mov ax,0x5
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        jmp L132
        nop
L28F:
        call far ptr helper_10
        jmp L9F
L297:
        xor ax,ax
L299:
    }
}
