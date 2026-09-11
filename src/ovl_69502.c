extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb028E;
extern int __near mn0256;
extern int __near mn4F4E;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_69502(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp lbl1BB
lbl0E:
        mov ax,mn6A06
        cmp ax,0x53
        jnz short $+5
        jmp lbl105
lbl19:
        jna short $+5
        jmp lbl1BB
lbl1E:
        sub al,0x13
        jz short $+23
        sub al,0x28
        jz short $+41
        sub al,0x9
        jnz short $+5
        jmp lblB9
lbl2D:
        dec al
        jnz short $+5
        jmp lblFF
lbl34:
        jmp lbl1BB
lbl37:
        mov ax,0x2a
lbl3A:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_0
lbl44:
        add sp,0x4
lbl47:
        mov ax,0x1
        jmp lbl1BD
lbl4D:
        mov ax,0x1
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x6
        or ax,ax
        jnz short $+7
        mov ax,0x2f
        jmp short $-43
lbl67:
        cmp byte ptr mb028E,0x0
        jz short $+7
        mov ax,0x31
        jmp short $+5
lbl73:
        mov ax,0x32
lbl76:
        mov dx,0xf015
        push dx
        push ax
        mov ax,0x30
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x6
        mov ax,0x13
        push ax
        push word ptr mn0256
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+5
        mov mn4F4E,ax
lblB2:
        mov ax,0x53
        jmp lbl1AD
        nop
lblB9:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_4
        add sp,0x4
        push dx
        push ax
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x6
        or ax,ax
        jz short $+7
        mov ax,0x1e8d
        jmp short $+5
lblE7:
        mov ax,0x1e95
lblEA:
        push ds
        push ax
        mov ax,0x33
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        jmp lbl47
lblFF:
        mov ax,0x34
        jmp lbl3A
lbl105:
        mov ax,0x1
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x6
        or ax,ax
        jz short $+9
        mov ax,0x2b
        jmp lbl3A
        nop
lbl121:
        cmp byte ptr mb028E,0x0
        jz short $+11
        mov ax,0x2d
        mov dx,0xf015
        jmp short $+8
        nop
lbl131:
        mov ax,0x1e7f
        mov dx,ds
lbl136:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x2c
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        mov ax,0x1
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x6
        mov ax,0x13
        push ax
        push word ptr mn0256
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+57
        mov mn4F4E,ax
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+34
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        mov ax,0x2e
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
lbl1AA:
        mov ax,0x3b
lbl1AD:
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        jmp lbl44
        nop
lbl1BB:
        xor ax,ax
lbl1BD:
    }
}
