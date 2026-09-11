extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb033D;
extern char __near mb0332;
extern char __near mb0333;
extern char __near mb033E;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_183707(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L1A3
L0B:
        mov ax,mn6A06
        cmp ax,0x4f
        jnz short $+5
        jmp LB1
L16:
        jna short $+5
        jmp L1A3
L1B:
        cmp al,0x2c
        jz short $+32
        ja short $+14
        sub al,0x8
        jz short $+26
        sub al,0xb
        jz short $+60
        jmp L1A3
        nop
L2D:
        sub al,0x38
        jz short $+74
        sub al,0xc
        jz short $+94
        dec al
        jz short $+98
        jmp L1A3
        nop
L3D:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2c
L51:
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L5D:
        mov ax,0x1
        jmp L1A5
L63:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2b
        jmp short $-38
L79:
        push word ptr mn6A02
        push word ptr mn6A04
        mov ax,0x4f
        push ax
        call far ptr helper_2
        add sp,0x6
        jmp L1A5
        nop
L91:
        mov byte ptr mb033D,0x1
        jmp L1A3
L99:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2d
        jmp short $-93
        nop
LB1:
        cmp word ptr mn6A02,0xd9
        jz short $+5
        jmp L17D
LBC:
        mov ax,0xfc
        push ax
        mov ax,0xd9
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+9
        mov ax,0x2e
        jmp L16C
        nop
LD7:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2f
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        cmp byte ptr mb0332,0x0
        jz short $+89
        cmp byte ptr mb0333,0x0
        jz short $+82
        mov ax,0xd9
        push ax
        mov ax,0xfe
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+62
        mov ax,0x30
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x1
        push ax
        mov ax,0xd9
        push ax
        mov cx,0xfe
        push cx
        call far ptr helper_4
        add sp,0x6
        mov ax,0x154
        push ax
        mov ax,0xd9
        push ax
        call far ptr helper_5
        add sp,0x4
        mov byte ptr mb033E,0x1
        jmp L5D
L169:
        mov ax,0x31
L16C:
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L5D
        nop
L17D:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x32
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L5D
        nop
L1A3:
        xor ax,ax
L1A5:
    }
}
