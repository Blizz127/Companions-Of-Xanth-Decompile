extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern char __near mb0366;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_291911(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+55
        jmp L121
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L121
L1A:
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1d
L2E:
        mov dx,0xf045
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L3A:
        mov ax,0x1
        jmp L123
        nop
L41:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LFB
L4C:
        jna short $+5
        jmp L121
L51:
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+18
        sub al,0x4
        jz short $+48
        sub al,0x15
        jz short $+5
        jmp L121
L64:
        mov ax,0x19
        jmp short $+59
L69:
        mov ax,0xe
        push ax
        mov ax,0x187
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x384c
        jmp short $+5
L81:
        mov ax,0x3852
L84:
        push ds
        push ax
        mov ax,0x18
        jmp short $-91
L8B:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+20
        mov ax,0x1b
LA2:
        mov dx,0xf045
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-117
LB1:
        mov ax,0x1c
        mov dx,0xf045
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x1
        push ax
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_3
        add sp,0x6
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        call far ptr helper_5
        mov ax,0xfa0
        push ax
        call far ptr helper_6
        add sp,0x2
        mov byte ptr mb0366,0x1
        jmp L3A
LFB:
        mov ax,0xe
        push ax
        mov ax,0x187
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x3856
        jmp short $+6
        nop
L115:
        mov ax,0x385c
L118:
        push ds
        push ax
        mov ax,0x1a
        jmp L2E
        nop
L121:
        xor ax,ax
L123:
    }
}
