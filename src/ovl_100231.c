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
int far ovl_100231(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L18F
L0B:
        mov ax,mn6A06
        cmp ax,0x47
        jnz short $+5
        jmp LE1
L16:
        jna short $+5
        jmp L18F
L1B:
        cmp al,0x2c
        jnz short $+5
        jmp LC1
L22:
        ja short $+13
        sub al,0xf
        jz short $+33
        sub al,0x4
        jz short $+95
        jmp L18F
L2F:
        sub al,0x38
        jnz short $+5
        jmp LE1
L36:
        sub al,0xc
        jnz short $+5
        jmp L159
L3D:
        dec al
        jnz short $+5
        jmp L169
L44:
        jmp L18F
L47:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2440
        push ds
        push ax
        call far ptr helper_1
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_2
L71:
        mov sp,bp
        mov ax,0x1
        push ax
        mov cx,0x6
        push cx
        call far ptr helper_3
L80:
        mov sp,bp
L82:
        mov ax,0x1
        jmp L191
        nop
L89:
        mov ax,0x10
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jz short $+9
        mov ax,0x17
        jmp L15C
        nop
LA3:
        mov ax,0x5a03
        push ax
        mov ax,0x113
        push ax
        call far ptr helper_5
        mov sp,bp
        mov ax,0x10
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        jmp short $-63
LC1:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1a
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_1
        jmp short $-110
LE1:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        cmp word ptr mn6A06,0x38
        jnz short $+7
        mov ax,0x2426
        jmp short $+5
LFF:
        mov ax,0x2429
L102:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        cmp word ptr mn6A06,0x38
        jnz short $+8
        mov ax,0x242c
        jmp short $+6
        nop
L123:
        mov ax,0x2430
L126:
        push ds
        push ax
        mov ax,0x1b
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_1
        add sp,0x14
        mov ax,0x2436
        push ds
        push ax
        call far ptr helper_7
        add sp,0x4
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x6
        jmp L82
        nop
L159:
        mov ax,0x18
L15C:
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_1
        jmp L80
L169:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x19
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L82
        nop
L18F:
        xor ax,ax
L191:
    }
}
