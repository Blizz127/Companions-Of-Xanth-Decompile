extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb3480;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_253386(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L153
L0F:
        jmp L337
        nop
L13:
        mov ax,mn6A06
        dec ax
        dec ax
        jz short $+10
        sub ax,0x36
        jz short $+5
        jmp L337
L22:
        cmp word ptr mn6A04,0x138
        jz short $+5
        jmp LED
L2D:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+25
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0xe
        jmp L140
L57:
        mov ax,0xa
        push ax
        push word ptr mn6A02
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+58
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
        mov ax,0xf
L92:
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_3
        add sp,0xc
        jmp L14D
        nop
LA3:
        push word ptr mn6A02
        mov ax,0x22
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
        mov ax,0x10
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_3
        add sp,0xc
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x6
        jmp short $+98
LED:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+44
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
        jmp L92
L12B:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x12
L140:
        mov dx,0xf027
        push dx
L144:
        push ax
        call far ptr helper_3
        add sp,0x8
L14D:
        mov ax,0x1
        jmp L339
L153:
        mov ax,mn6A06
        cmp ax,0x4c
        jnz short $+5
        jmp L293
L15E:
        jna short $+5
        jmp L337
L163:
        cmp al,0x38
        jnz short $+5
        jmp L319
L16A:
        ja short $+23
        sub al,0x8
        jz short $+40
        sub al,0xb
        jnz short $+5
        jmp L1FB
L177:
        sub al,0x19
        jnz short $+5
        jmp L293
L17E:
        jmp L337
L181:
        sub al,0x44
        jnz short $+5
        jmp L319
L188:
        dec al
        jnz short $+5
        jmp L331
L18F:
        sub al,0x6
        jz short $+5
        jmp L337
L196:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+27
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xa
        jmp L140
        nop
L1C3:
        mov ax,0xb
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        mov ax,0x4c
L1E6:
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        mov byte ptr mb3480,0x0
        jmp L14D
L1FB:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_3
        add sp,0x8
        mov ax,0xa
        push ax
        mov ax,0x137
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+44
        push word ptr mn6A04
        mov ax,0x138
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x3
        jmp short $+6
        nop
L24B:
        mov ax,0x4
L24E:
        mov dx,0xf027
        push dx
        push ax
        mov ax,0x3481
        push ds
        jmp L144
        nop
L25B:
        mov ax,0x3488
        push ds
        push ax
        call far ptr helper_3
        add sp,0x4
        push word ptr mn6A04
        mov ax,0x138
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L14D
L27F:
        mov ax,0x5
L282:
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_3
        add sp,0x4
        jmp L14D
        nop
L293:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
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
        mov ax,0x6
        jmp L140
L2BF:
        push word ptr mn6A04
        mov ax,0x138
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x8
        jmp short $+6
        nop
L2D9:
        mov ax,0x9
L2DC:
        mov dx,0xf027
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x7
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_3
        add sp,0xc
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x4
        mov ax,0x4b
        jmp L1E6
L319:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xd
        jmp L140
L331:
        mov ax,0xc
        jmp L282
L337:
        xor ax,ax
L339:
    }
}
