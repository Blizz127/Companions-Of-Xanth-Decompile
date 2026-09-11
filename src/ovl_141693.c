extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_141693(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L2FF
L0B:
        mov ax,mn6A06
        cmp ax,0x47
        jnz short $+5
        jmp L243
L16:
        jna short $+5
        jmp L2FF
L1B:
        cmp al,0x2c
        jz short $+46
        ja short $+20
        sub al,0x8
        jz short $+40
        sub al,0x7
        jz short $+102
        sub al,0x4
        jnz short $+5
        jmp LFB
L30:
        jmp L2FF
L33:
        sub al,0x38
        jnz short $+5
        jmp L16F
L3A:
        sub al,0xc
        jnz short $+5
        jmp L1D3
L41:
        dec al
        jnz short $+5
        jmp L23D
L48:
        jmp L2FF
L4B:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x46
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        cmp word ptr mn6A06,0x2c
        jnz short $+7
        mov ax,0x47
        jmp short $+5
L77:
        mov ax,0x48
L7A:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L86:
        mov ax,0x1
        jmp L301
        nop
L8D:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+25
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x4d
        jmp L26C
LB7:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x4e
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        xor ax,ax
        push ax
        mov ax,0x9d
        push ax
LE0:
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x6
        mov ax,0xe
        push ax
        call far ptr helper_4
LF5:
        add sp,0x2
        jmp short $-114
        nop
LFB:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+8
        mov ax,0x40
        jmp L7A
L115:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2988
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x2
        sub ax,0x125
        jz short $+12
        dec ax
        jz short $+15
        dec ax
        jz short $+18
        jmp L86
        nop
L14F:
        mov ax,0x41
        jmp L7A
L155:
        mov ax,0x42
        jmp L7A
L15B:
        mov ax,0x43
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L86
        nop
L16F:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x4a
        jmp L26C
L19B:
        mov ax,mn6A02
        sub ax,0xa2
        jz short $+5
        jmp L2FF
L1A6:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x4b
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        xor ax,ax
        push ax
        push word ptr mn0256
        jmp LE0
        nop
L1D3:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x44
        jmp short $+112
        nop
L1FF:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x45
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x125
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        push word ptr mn6A04
        call far ptr helper_7
        jmp LF5
L23D:
        mov ax,0x49
        jmp L7A
L243:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+40
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x4f
L26C:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L86
        nop
L27D:
        cmp word ptr mn0256,0x9d
        jnz short $+56
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x50
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp short $+48
L2BB:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x51
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0xe
        push ax
        call far ptr helper_4
        add sp,0x2
L2E9:
        xor ax,ax
        push ax
        mov ax,0x9d
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x6
        jmp L86
L2FF:
        xor ax,ax
L301:
    }
}
