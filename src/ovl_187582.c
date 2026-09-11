extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb0321;
extern char __near mb2FFE;
extern int __near mn0798;
extern int __near mn0290;
extern char __near mb032B;
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
int far ovl_187582(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+109
        jmp L217
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L217
L1A:
        mov ax,mn6A04
        sub ax,0xce
        jz short $+10
        sub ax,0x20
        jz short $+5
        jmp L217
L2A:
        mov ax,0x1
        push ax
        mov ax,0xee
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+8
        mov ax,0x25
        jmp short $+36
        nop
L43:
        cmp byte ptr mb0321,0x0
        jz short $+25
        mov ax,0xee
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x26
        jmp short $+6
        nop
L61:
        mov ax,0x27
L64:
        mov dx,0xf01f
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
L70:
        mov ax,0x1
        jmp L219
        nop
L77:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L133
L82:
        jna short $+5
        jmp L217
L87:
        cmp al,0x2c
        jz short $+76
        ja short $+14
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+40
        jmp L217
        nop
L99:
        sub al,0x38
        jz short $+122
        sub al,0xc
        jz short $+124
        jmp L217
        nop
LA5:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x1f
        jmp short $-85
LBB:
        cmp byte ptr mb0321,0x0
        jz short $+11
        mov ax,0x1b
        mov dx,0xf01f
        jmp short $+6
        nop
LCB:
        xor ax,ax
        cwd
LCE:
        push dx
        push ax
        mov ax,0x1a
        jmp short $-111
LD5:
        cmp byte ptr mb0321,0x0
        jz short $+21
        mov ax,0x1d
LDF:
        mov dx,0xf01f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $-124
        nop
LEF:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e
L104:
        mov dx,0xf01f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp L70
        nop
L115:
        mov ax,0x24
        jmp short $-57
        nop
L11B:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1c
        jmp L64
L133:
        cmp byte ptr mb0321,0x0
        jnz short $+5
        jmp L1FF
L13D:
        mov ax,0x20
        mov dx,0xf01f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x7d0
        push ax
        call far ptr helper_3
        add sp,0x2
        mov ax,0x21
        mov dx,0xf01f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0xfa0
        push ax
        call far ptr helper_3
        add sp,0x2
        mov ax,0x22
        mov dx,0xf01f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov byte ptr mb0321,0x0
        mov ax,0x2c
        push ax
        call far ptr helper_4
        add sp,0x2
        mov byte ptr mb2FFE,0x0
        mov ax,0x5
        mov mn0798,ax
        mov mn0290,ax
        call far ptr helper_5
        call far ptr helper_6
        mov ax,0x3030
        push ds
        push ax
        call far ptr helper_7
        add sp,0x4
        mov ax,0x1770
        push ax
        call far ptr helper_3
        add sp,0x2
        mov byte ptr mb032B,0x1
        xor ax,ax
        push ax
        push ax
        mov cx,0xf1
        push cx
        call far ptr helper_8
        add sp,0x6
        mov ax,0x5a03
        push ax
        mov ax,0x151
        push ax
        call far ptr helper_9
        add sp,0x4
        xor ax,ax
        push ax
        push ax
        mov ax,0xc
        push ax
        call far ptr helper_10
        add sp,0x6
        jmp L70
L1FF:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x23
        jmp L104
L217:
        xor ax,ax
L219:
    }
}
