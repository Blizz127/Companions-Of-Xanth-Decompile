extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb0362;
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
int far ovl_280555(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L1ED
L0B:
        mov ax,mn6A06
        cmp ax,0x4e
        jnz short $+5
        jmp LEB
L16:
        jna short $+5
        jmp L1ED
L1B:
        cmp al,0x38
        jz short $+108
        ja short $+18
        sub al,0x8
        jz short $+36
        sub al,0xb
        jz short $+50
        sub al,0x19
        jz short $+28
        jmp L1ED
        nop
L31:
        sub al,0x44
        jnz short $+5
        jmp LC7
L38:
        dec al
        jnz short $+5
        jmp LDF
L3F:
        sub al,0x3
        jz short $+72
        jmp L1ED
        nop
L47:
        push word ptr mn6A04
        call far ptr helper_0
L50:
        mov sp,bp
L52:
        mov ax,0x1
        jmp L1EF
        nop
L59:
        mov ax,0x16c
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x37
        jmp short $+5
L71:
        mov ax,0x38
L74:
        mov dx,0xf03e
        push dx
        push ax
        mov ax,0x36
L7C:
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_2
        jmp short $-54
        nop
L89:
        cmp word ptr mn6A02,0x16c
        jnz short $+5
        jmp L1ED
L94:
        cmp word ptr mn6A02,0x16d
        jnz short $+5
        jmp L1ED
L9F:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_3
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x3a
        jmp short $+97
LC7:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x39
        jmp short $-96
        nop
LDF:
        push word ptr mn6A04
        call far ptr helper_4
        jmp L50
LEB:
        mov ax,0x16c
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+58
        mov ax,0x16c
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x3b
L126:
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        jmp L52
        nop
L137:
        mov ax,0x16d
        push ax
        mov cx,0x22
        push cx
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x16c
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x3c
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_2
        add sp,0x10
        mov ax,0x1
        push ax
        mov ax,0x16d
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x6
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        or ax,ax
        jnz short $+37
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_8
        add sp,0x6
L1C8:
        mov ax,0x48
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x4
        call far ptr helper_10
        or ax,ax
        jnz short $+5
        jmp L52
L1E4:
        mov byte ptr mb0362,0x1
        jmp L52
        nop
L1ED:
        xor ax,ax
L1EF:
    }
}
