extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb0373;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_288625(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+55
        jmp L10B
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L10B
L1A:
        push word ptr mn6A04
        mov ax,0x23
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x14
L2E:
        mov dx,0xf02e
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L3A:
        mov ax,0x1
        jmp L10D
        nop
L41:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+110
        jna short $+5
        jmp L10B
L4E:
        sub al,0x8
        jz short $+13
        sub al,0xb
        jz short $+43
        sub al,0x19
        jz short $+5
        jmp L10B
L5D:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x37c8
        jmp short $+5
L75:
        mov ax,0x37cf
L78:
        push ds
        push ax
        mov ax,0x11
        jmp short $-79
L7F:
        mov ax,0x182
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x10
        mov dx,0xf02e
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp short $-121
LB5:
        mov ax,0x5a0e
        push ax
        mov ax,0x267
        push ax
        call far ptr helper_3
        add sp,0x4
        cmp byte ptr mb0373,0x0
        jz short $+45
        mov byte ptr mb0373,0x0
        mov ax,0x12
        mov dx,0xf02e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x6
        push ax
        call far ptr helper_4
        add sp,0x6
        jmp L3A
LF7:
        mov ax,0x13
        mov dx,0xf02e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L3A
        nop
L10B:
        xor ax,ax
L10D:
    }
}
