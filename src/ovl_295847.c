extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern int __near mn0256;
extern char __near mb036B;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_295847(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp L189
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L189
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
        mov ax,0x19
L40:
        mov dx,0xf02b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L4C:
        mov ax,0x1
        jmp L18B
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L16F
L5E:
        jna short $+5
        jmp L189
L63:
        cmp al,0x21
        jz short $+74
        ja short $+14
        sub al,0x8
        jz short $+25
        sub al,0xb
        jz short $+58
        jmp L189
        nop
L75:
        sub al,0x2c
        jz short $+13
        sub al,0xc
        jz short $+9
        sub al,0xc
        jz short $+5
        jmp L189
L84:
        cmp word ptr mn0256,0x18d
        jz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x13
        jmp short $-96
        nop
LA3:
        mov ax,0x14
        jmp short $-102
        nop
LA9:
        mov ax,0x12
        jmp short $-108
        nop
LAF:
        cmp word ptr mn0256,0x18a
        jnz short $+8
        mov ax,0x16
        jmp short $-122
        nop
LBD:
        mov ax,0xe
        push ax
        mov ax,0x190
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+9
        mov ax,0x17
        jmp L40
        nop
LD7:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x18
        mov dx,0xf02b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x9c4
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0xe
        push ax
        mov ax,0x190
        push ax
        call far ptr helper_4
        mov sp,bp
        call far ptr helper_5
        mov ax,0xbb8
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0xa
        push ax
        mov ax,0x192
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+11
        mov ax,0x5a1c
        push ax
        mov ax,0x257
        jmp short $+18
L13D:
        mov ax,0x5a1c
        push ax
        cmp byte ptr mb036B,0x1
        sbb ax,ax
        and al,0xfd
        add ax,0x250
L14D:
        push ax
        call far ptr helper_6
        add sp,0x4
        mov byte ptr mb036B,0x1
        mov ax,0x3
        push ax
        mov ax,0x23
        push ax
        call far ptr helper_7
        add sp,0x4
        jmp L4C
        nop
L16F:
        cmp word ptr mn0256,0x18d
        jnz short $+8
        mov ax,0x38e7
        jmp short $+6
        nop
L17D:
        mov ax,0x38ea
L180:
        push ds
        push ax
        mov ax,0x15
        jmp L40
        nop
L189:
        xor ax,ax
L18B:
    }
}
