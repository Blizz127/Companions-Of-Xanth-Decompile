extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb0323;
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
int far ovl_73400(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+12
        dec ax
        dec ax
        jnz short $+5
        jmp LD9
L12:
        jmp L2F9
L15:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L2F9
L20:
        cmp word ptr mn6A04,0x25
        jz short $+46
        cmp word ptr mn6A04,0x26
        jz short $+39
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x17
L43:
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp LD3
L53:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+56
        push word ptr mn6A02
        mov ax,0x22
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
        mov ax,0x15
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp short $+56
L9D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x16
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x1
        push ax
        push word ptr mn6A02
LC7:
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x6
LD3:
        mov ax,0x1
        jmp L2FB
LD9:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L2F1
LE4:
        jna short $+5
        jmp L2F9
LE9:
        cmp al,0x2c
        jz short $+94
        ja short $+14
        sub al,0x8
        jz short $+22
        sub al,0xb
LF5:
        jz short $+38
        jmp L2F9
        nop
LFB:
        sub al,0x38
        jnz short $+5
        jmp L249
L102:
        sub al,0x2
        jmp short $-15
        nop
L107:
        mov ax,0x107
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        jmp L2F9
        nop
L11B:
        cmp byte ptr mb0323,0x0
        jz short $+9
        mov ax,0x1f22
        mov dx,ds
        jmp short $+5
L129:
        xor ax,ax
        cwd
L12C:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0xf
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x10
        jmp short $+69
L149:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
        jmp L43
L175:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        or ax,ax
        jz short $+22
        mov ax,0x12
L18C:
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_1
L196:
        add sp,0x4
        jmp LD3
        nop
L19D:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        or ax,ax
        jz short $+36
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x1f26
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $+73
        nop
L1D3:
        mov ax,0x13
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x4
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov dx,0x26
        push dx
        call far ptr helper_3
        add sp,0x6
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x25
        push ax
        call far ptr helper_3
        add sp,0x6
L219:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x4
        mov ax,0x109
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        mov ax,0x8
        push ax
        push word ptr mn6A04
        call far ptr helper_8
        jmp L196
L249:
        cmp word ptr mn6A02,0x23
        jz short $+5
        jmp L2F9
L253:
        mov ax,0x1f34
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        or ax,ax
        jz short $+81
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x1f39
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x4
        mov ax,0x107
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        mov ax,0x2c
        push ax
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x4
L2C3:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x1
        push ax
        mov cx,0x23
        push cx
        jmp LC7
        nop
L2F1:
        call far ptr helper_10
        jmp LD3
L2F9:
        xor ax,ax
L2FB:
    }
}
