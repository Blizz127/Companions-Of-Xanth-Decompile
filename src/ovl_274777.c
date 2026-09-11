extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern char __near mb35FC;
extern char __near mb0358;
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
int far ovl_274777(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L249
L0F:
        jmp L34B
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L34B
L1E:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+104
        cmp word ptr mn6A04,0x164
        jnz short $+56
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
L5F:
        mov dx,0xf03c
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        jmp L242
        nop
L6F:
        push word ptr mn6A02
        mov ax,0x22
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
        mov ax,0xc
        jmp short $-54
L97:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xd
        jmp L235
LC3:
        cmp word ptr mn6A04,0x15e
        jz short $+5
        jmp L19D
LCE:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xe
        mov dx,0xf03c
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0x1b58
        push ax
        call far ptr helper_3
        add sp,0x2
        mov byte ptr mb35FC,0x0
        mov ax,0xa
        push ax
        mov ax,0x165
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0x40
        push ax
        call far ptr helper_5
        add sp,0x2
        xor ax,ax
        push ax
        mov cx,0x9
        push cx
        mov dx,0x165
        push dx
        call far ptr helper_6
        add sp,0x6
        mov ax,0x1
        push ax
        push word ptr mn6A02
        mov ax,0x15e
        push ax
        call far ptr helper_6
        add sp,0x6
        mov ax,0x5a15
        push ax
        mov ax,0x3e3
        push ax
        call far ptr helper_7
        add sp,0x4
        mov byte ptr mb0358,0x1
        xor ax,ax
        push ax
        push ax
        mov cx,0x9
        push cx
        call far ptr helper_6
        add sp,0x6
        mov byte ptr mb35FC,0x0
        mov ax,0x20
        mov cx,0x2199
        push cx
        push ax
        call far ptr helper_8
        add sp,0x4
        mov ax,0x20
        push ax
        call far ptr helper_5
        add sp,0x2
        xor ax,ax
        push ax
        push ax
        mov ax,0xc
        push ax
        call far ptr helper_9
        add sp,0x6
        jmp L242
L19D:
        mov ax,0x3630
        push ds
        push ax
        call far ptr helper_2
        add sp,0x4
        push word ptr mn6A02
        mov ax,0x164
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+39
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xf
        mov dx,0xf03c
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $+52
        nop
L1E3:
        mov ax,0x15e
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
        mov ax,0x3635
        push ds
        push ax
        call far ptr helper_2
        add sp,0xc
L214:
        push word ptr mn6A02
        mov ax,0x164
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x3640
        jmp short $+5
L22D:
        mov ax,0x364e
L230:
        push ds
        push ax
        mov ax,0x10
L235:
        mov dx,0xf03c
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
L242:
        mov ax,0x1
        jmp L34D
        nop
L249:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L345
L254:
        jna short $+5
        jmp L34B
L259:
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+92
        sub al,0x19
        jnz short $+5
        jmp L305
L268:
        jmp L34B
L26B:
        mov ax,0x163
        push ax
        mov ax,0x164
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x8
        jmp L31C
L285:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x15e
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x9
        mov dx,0xf03c
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        jmp short $-119
L2BB:
        push word ptr mn6A04
        mov ax,0x15e
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x4
        jmp short $+74
        nop
L2D5:
        push word ptr mn6A04
        mov ax,0x164
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L242
L2EC:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x5
        jmp L235
        nop
L305:
        push word ptr mn6A04
        mov ax,0x15e
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+22
        mov ax,0x6
L31C:
        mov dx,0xf03c
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp L242
        nop
L32D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x7
        jmp L235
L345:
        mov ax,0xa
        jmp short $-44
        nop
L34B:
        xor ax,ax
L34D:
    }
}
