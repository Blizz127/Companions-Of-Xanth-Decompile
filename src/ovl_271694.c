extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
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
int far ovl_271694(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+97
        jmp L299
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L299
L1A:
        mov ax,0x163
        push ax
        push word ptr mn6A02
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+24
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x30
        jmp short $+23
L43:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x31
L58:
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
L65:
        mov ax,0x1
        jmp L29B
L6B:
        mov ax,mn6A06
        cmp ax,0x53
        jnz short $+5
        jmp L233
L76:
        jna short $+5
        jmp L299
L7B:
        sub al,0x8
        jz short $+24
        sub al,0xb
        jz short $+44
        sub al,0x19
        jnz short $+5
        jmp L11B
L8A:
        sub al,0x18
        jnz short $+5
        jmp L14D
L91:
        jmp L299
        nop
L95:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2b
        jmp short $-82
        nop
LAD:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x22
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x23
        jmp L222
LE9:
        mov ax,0x15d
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x24
        jmp L222
L103:
        push word ptr mn6A04
        mov ax,0x14
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x25
        jmp L58
L11B:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x29
        jmp L222
L135:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2a
        jmp L58
L14D:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x26
        jmp L58
L179:
        mov ax,0x15d
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L21F
L190:
        call far ptr helper_3
        push ax
        mov ax,0x22d
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0x15d
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
        mov ax,0x27
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        mov ax,0x15e
        push ax
        call far ptr helper_5
        add sp,0x2
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp L65
L1F9:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x7
        push ax
        call far ptr helper_8
        add sp,0x6
        jmp L65
L21F:
        mov ax,0x28
L222:
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp L65
        nop
L233:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+52
        mov ax,0x2c
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1770
        push ax
        call far ptr helper_9
        add sp,0x2
        mov ax,0x5a03
        push ax
        mov ax,0x180
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0x2d
        jmp short $-84
        nop
L279:
        mov ax,0x163
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x2e
        jmp short $-110
        nop
L293:
        mov ax,0x2f
        jmp short $-116
        nop
L299:
        xor ax,ax
L29B:
    }
}
