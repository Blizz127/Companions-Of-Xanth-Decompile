extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb0353;
extern char __near mb02F3;
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
int far ovl_132070(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L155
L0F:
        jmp L271
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L271
L1E:
        cmp word ptr mn6A04,0x58
        jnz short $+56
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+37
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x1a
L4C:
        mov dx,0xf00f
        push dx
        push ax
        call far ptr helper_2
L56:
        mov sp,bp
        jmp L14F
L5B:
        cmp word ptr mn6A04,0x73
        jz short $+5
        jmp L109
L65:
        mov ax,0x73
        push ax
        call far ptr helper_3
        mov sp,bp
        cmp ax,0x12d
        jz short $+5
        jmp L109
L78:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jz short $+8
        mov ax,0x1c
        jmp short $-66
        nop
L91:
        cmp word ptr mn6A04,0x73
        jnz short $+27
        mov ax,0x98
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jz short $+8
        mov ax,0x1d
        jmp short $-98
        nop
LB1:
        mov ax,0x1e
        mov dx,0xf00f
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_5
        mov sp,bp
        cmp byte ptr mb0353,0x0
        jnz short $+119
        mov ax,0x1
        mov mb0353,al
        push ax
        push ax
        mov ax,0xf
        push ax
        call far ptr helper_6
        mov sp,bp
        mov ax,0x1b58
        push ax
        call far ptr helper_7
        mov sp,bp
        mov ax,0x5a03
        push ax
        mov ax,0x183
        push ax
        call far ptr helper_8
        jmp L56
        nop
L109:
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_1
        add sp,0x4
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
        mov ax,0x1b
        mov dx,0xf00f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x10
L14F:
        mov ax,0x1
        jmp L273
L155:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L259
L160:
        jna short $+5
        jmp L271
L165:
        cmp al,0x29
        jnz short $+5
        jmp L20D
L16C:
        ja short $+13
        sub al,0x8
        jz short $+37
        sub al,0xb
        jz short $+47
        jmp L271
L179:
        sub al,0x2c
        jz short $+26
        sub al,0xa
        jnc short $+5
        jmp L271
L184:
        sub al,0x1
        ja short $+5
        jmp L24D
L18B:
        sub al,0xd
        jnz short $+5
        jmp L253
L192:
        jmp L271
L195:
        push word ptr mn6A04
        call far ptr helper_9
L19E:
        add sp,0x2
        jmp short $-82
L1A3:
        mov ax,0x11
        mov dx,0xf00f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        push word ptr mn6A04
        mov ax,0x73
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+44
        mov ax,0x12
        mov dx,0xf00f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x73
        push ax
        mov ax,0x8a
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+24
        mov ax,0x13
        jmp short $+6
        nop
L1F1:
        mov ax,0x14
L1F4:
        mov dx,0xf00f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
L201:
        mov ax,0x2e
        push ax
        call far ptr helper_10
        jmp short $-108
        nop
L20D:
        cmp byte ptr mb02F3,0x0
        jz short $+39
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x18
L229:
        mov dx,0xf00f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp L14F
L239:
        mov ax,0x19
L23C:
        mov dx,0xf00f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp L14F
        nop
L24D:
        mov ax,0x16
        jmp short $-20
        nop
L253:
        mov ax,0x15
        jmp short $-26
        nop
L259:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x17
        jmp short $-69
        nop
L271:
        xor ax,ax
L273:
    }
}
