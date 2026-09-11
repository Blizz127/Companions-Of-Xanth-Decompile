extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb030C;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_101640(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L133
L0F:
        jmp L191
        nop
L13:
        mov ax,mn6A06
        cmp ax,0x47
        jz short $+18
        jna short $+5
        jmp L191
L20:
        sub al,0x2
        jz short $+9
        sub al,0x36
        jz short $+121
        jmp L191
L2B:
        cmp word ptr mn6A04,0x90
        jz short $+13
        cmp word ptr mn6A04,0x92
        jz short $+5
        jmp L191
L3E:
        push word ptr mn6A02
        mov ax,0x73
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+58
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x35
L77:
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_2
L81:
        mov sp,bp
L83:
        mov ax,0x1
        jmp L193
L89:
        mov ax,0x73
        push ax
        push word ptr mn6A04
        push word ptr mn6A06
        call far ptr helper_3
        mov sp,bp
        jmp L193
L9F:
        cmp word ptr mn6A04,0x73
        jz short $+7
        mov ax,0x36
        jmp short $-50
LAB:
        cmp byte ptr mb030C,0x0
        jz short $+61
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x3
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x3
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x37
        jmp short $-115
        nop
LED:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x38
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_4
        jmp L81
L133:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+64
        ja short $+86
        sub al,0x13
        jz short $+8
        sub al,0x31
        jz short $+48
        jmp short $+76
L147:
        mov ax,0x31
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x72
        push ax
        mov ax,0x73
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+5
        jmp L83
L16C:
        mov ax,0x32
        jmp L77
        nop
L173:
        mov ax,0x33
        jmp L77
L179:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x34
        jmp L77
        nop
L191:
        xor ax,ax
L193:
    }
}
